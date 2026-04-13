#!/usr/bin/env python3
import json
import subprocess
import time


SESSKEY = "nalAOrEc44"
QUIZ_CMID = "1886213"
QUESTION_IDS = list(range(749328, 749341))  # 01~13 latest set


def run_applescript(script: str) -> str:
    result = subprocess.run(
        ["osascript", "-e", script],
        check=True,
        capture_output=True,
        text=True,
    )
    return result.stdout.strip()


def safari_find_ecampus_tab() -> None:
    script = r'''
tell application "Safari"
  repeat with w in windows
    repeat with t in tabs of w
      set u to URL of t
      if u contains "ecampus.kookmin.ac.kr" then
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
    safari_find_ecampus_tab()
    script = f'''
tell application "Safari"
  set URL of current tab of front window to {json.dumps(url, ensure_ascii=False)}
end tell
'''
    run_applescript(script)


def safari_url() -> str:
    safari_find_ecampus_tab()
    return run_applescript('tell application "Safari" to return URL of current tab of front window')


def safari_js(js: str) -> str:
    safari_find_ecampus_tab()
    script = f'''
tell application "Safari"
  return do JavaScript {json.dumps(js, ensure_ascii=False)} in current tab of front window
end tell
'''
    return run_applescript(script)


def wait_until(predicate, timeout: float = 20.0, interval: float = 0.5) -> None:
    deadline = time.time() + timeout
    while time.time() < deadline:
        if predicate():
            return
        time.sleep(interval)
    raise RuntimeError("Timed out waiting for Safari/eCampus state.")


def existing_count() -> int:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    value = safari_js(
        """
(() => {
  const text = document.body.innerText || "";
  return (text.match(/배열포인터 중간퀴즈/g) || []).length;
})();
"""
    ).strip()
    return int(float(value or "0"))


def attach_all() -> None:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    js = (
        "(function(){"
        f"var qids={json.dumps(QUESTION_IDS)};"
        f"var sesskey={json.dumps(SESSKEY)};"
        f"var cmid={json.dumps(QUIZ_CMID)};"
        'var form=document.createElement("form");'
        'form.method="POST";'
        'form.action="https://ecampus.kookmin.ac.kr/mod/quiz/edit.php";'
        'function add(name,value){var i=document.createElement("input");i.type="hidden";i.name=name;i.value=value;form.appendChild(i);}'
        'add("sesskey", sesskey);'
        'add("cmid", cmid);'
        'add("add", "선택한 문제를 퀴즈에 추가");'
        'qids.forEach(function(id){ add("q" + id, "1"); });'
        'document.body.appendChild(form);'
        'form.submit();'
        'return "submitted";'
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url(), timeout=30)


def verify() -> dict:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    return json.loads(
        safari_js(
            """
(() => {
  const text = document.body.innerText || "";
  return JSON.stringify({
    count: (text.match(/배열포인터 중간퀴즈/g) || []).length,
    problemCountLine: (text.match(/출제 문제 수\\s*:?\\s*\\d+/) || [""])[0],
    totalLine: (text.match(/총점\\s*:?\\s*[0-9.]+/) || [""])[0]
  });
})();
"""
        )
    )


def main() -> int:
    count = existing_count()
    print(f"existing_count={count}", flush=True)
    if count == 0:
        attach_all()
    else:
        print("Questions already present in quiz; skipping attach.", flush=True)
    result = verify()
    print(json.dumps(result, ensure_ascii=False, indent=2), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
