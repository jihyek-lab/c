#!/usr/bin/env python3
import json
import subprocess
import sys
import time


def run_applescript(script: str) -> str:
    result = subprocess.run(
        ["osascript", "-e", script],
        check=True,
        capture_output=True,
        text=True,
    )
    return result.stdout.strip()


def safari_find_qbank() -> None:
    script = r'''
tell application "Safari"
  repeat with w in windows
    repeat with t in tabs of w
      if URL of t contains "ecampus.kookmin.ac.kr/question/edit.php?courseid=83169" then
        set current tab of w to t
        set index of w to 1
        activate
        return
      end if
    end repeat
  end repeat
end tell
'''
    run_applescript(script)


def safari_open(url: str) -> None:
    safari_find_qbank()
    script = f'''
tell application "Safari"
  set URL of current tab of front window to {json.dumps(url, ensure_ascii=False)}
end tell
'''
    run_applescript(script)


def safari_js(js: str) -> str:
    safari_find_qbank()
    script = f'''
tell application "Safari"
  return do JavaScript {json.dumps(js, ensure_ascii=False)} in current tab of front window
end tell
'''
    return run_applescript(script)


def main() -> int:
    if len(sys.argv) > 1 and sys.argv[1] == "pages":
        js = """
(() => JSON.stringify(
  [...document.querySelectorAll('a[href]')]
    .map(a => ({text:(a.textContent||'').trim(), href:a.href}))
    .filter(x => x.href.includes('/question/edit.php'))
    .slice(0, 50)
))();
"""
        print(safari_js(js))
        return 0

    if len(sys.argv) > 2 and sys.argv[1] == "qpage":
        qpage = sys.argv[2]
        keyword = sys.argv[3] if len(sys.argv) > 3 else "배열포인터 중간퀴즈 11번"
        safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?courseid=83169&qpage={qpage}")
        time.sleep(1.5)
        js = f"""
(() => {{
  const text = document.body.innerText || "";
  return text.includes({json.dumps(keyword)}) ? "FOUND" : text.slice(0, 2000);
}})();
"""
        print(safari_js(js))
        return 0

    keyword = sys.argv[1] if len(sys.argv) > 1 else "배열포인터 중간퀴즈 01번"
    js = f"""
(() => {{
  const keyword = {json.dumps(keyword)};
  const rows = [...document.querySelectorAll('tr')].filter(tr => (tr.innerText || '').includes(keyword));
  return JSON.stringify(rows.slice(0, 4).map(tr => ({{
    text: (tr.innerText || '').slice(0, 800),
    html: tr.outerHTML.slice(0, 4000)
  }})));
}})();
"""
    print(safari_js(js))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
