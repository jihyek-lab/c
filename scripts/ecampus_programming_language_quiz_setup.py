#!/usr/bin/env python3
import json
import subprocess
import sys
import time
from urllib.parse import parse_qs, urlparse


def run_applescript(script: str) -> str:
    result = subprocess.run(
        ["osascript", "-e", script],
        check=True,
        capture_output=True,
        text=True,
    )
    return result.stdout.strip()


def safari_find_ecampus_tab() -> str:
    script = r'''
tell application "Safari"
  set foundInfo to ""
  repeat with w in windows
    repeat with t in tabs of w
      set u to URL of t
      if u contains "ecampus.kookmin.ac.kr" then
        set current tab of w to t
        set index of w to 1
        activate
        set foundInfo to u
        exit repeat
      end if
    end repeat
    if foundInfo is not "" then exit repeat
  end repeat
  return foundInfo
end tell
'''
    return run_applescript(script)


def safari_js(js: str) -> str:
    script = f'''
tell application "Safari"
  return do JavaScript {json.dumps(js, ensure_ascii=False)} in current tab of front window
end tell
'''
    return run_applescript(script)


def safari_open(url: str) -> None:
    script = f'''
tell application "Safari"
  set URL of current tab of front window to {json.dumps(url, ensure_ascii=False)}
end tell
'''
    run_applescript(script)


def wait_until(predicate, timeout: float = 20.0, interval: float = 0.5) -> None:
    deadline = time.time() + timeout
    while time.time() < deadline:
        if predicate():
            return
        time.sleep(interval)
    raise RuntimeError("Timed out waiting for Safari state.")


def inspect_current_quiz() -> dict:
    safari_find_ecampus_tab()
    data = json.loads(
        safari_js(
            """
(() => {
  const links = [...document.querySelectorAll("a[href]")].map(a => a.href);
  return JSON.stringify({
    url: location.href,
    title: (document.getElementById("id_name") || {}).value || "",
    qbLink: links.find(h => /question\\/edit\\.php\\?courseid=\\d+/.test(h)) || "",
    courseLink: links.find(h => /course\\/view\\.php\\?id=\\d+/.test(h)) || "",
    sesskey: (window.M && window.M.cfg && window.M.cfg.sesskey) || ""
  });
})();
"""
        )
    )
    return data


def inspect_qbank(courseid: str) -> dict:
    safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?courseid={courseid}")
    wait_until(lambda: "question/edit.php" in safari_js("location.href"))
    data = json.loads(
        safari_js(
            """
(() => {
  const sel = document.querySelector('select[name="category"]');
  return JSON.stringify({
    url: location.href,
    category: sel ? sel.value : "",
    categories: sel ? [...sel.options].slice(0,8).map(o => ({value:o.value, text:o.textContent.trim()})) : []
  });
})();
"""
        )
    )
    return data


def dump_qbank_question_links(courseid: str) -> list[dict]:
    safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?courseid={courseid}")
    wait_until(lambda: "question/edit.php" in safari_js("location.href"))
    return json.loads(
        safari_js(
            """
(() => {
  const rows = [];
  for (const a of document.querySelectorAll('a[href*="/question/question.php"]')) {
    const href = a.href || "";
    const tr = a.closest("tr");
    const row = tr ? tr.innerText.trim() : "";
    if (row.includes("배열포인터 중간퀴즈")) {
      rows.push({text: (a.textContent || "").trim(), href, row});
    }
  }
  return JSON.stringify(rows);
})();
"""
        )
    )


def dump_qbank_html_slice(courseid: str, keyword: str) -> str:
    safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?courseid={courseid}")
    wait_until(lambda: "question/edit.php" in safari_js("location.href"))
    return safari_js(
        f"""
(() => {{
  const html = document.documentElement.outerHTML;
  const idx = html.indexOf({json.dumps(keyword)});
  if (idx < 0) return "NOT_FOUND";
  return html.slice(Math.max(0, idx - 1500), Math.min(html.length, idx + 3000));
}})();
"""
    )


def main() -> int:
    info = inspect_current_quiz()
    print(json.dumps(info, ensure_ascii=False, indent=2))
    if info["qbLink"]:
        parsed = urlparse(info["qbLink"])
        courseid = parse_qs(parsed.query).get("courseid", [""])[0]
        print("courseid:", courseid)
        qbank = inspect_qbank(courseid)
        print(json.dumps(qbank, ensure_ascii=False, indent=2))
        if len(sys.argv) > 1 and sys.argv[1] == "dumpqbank":
            print(json.dumps(dump_qbank_question_links(courseid), ensure_ascii=False, indent=2))
        if len(sys.argv) > 2 and sys.argv[1] == "htmlslice":
            print(dump_qbank_html_slice(courseid, sys.argv[2]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
