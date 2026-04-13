#!/usr/bin/env python3
import html
import json
import re
import subprocess
import time


COURSE_ID = "83169"
SESSKEY = "nalAOrEc44"
CATEGORY = "118165,2202824"
OLD_QUIZ_CMID = "1886213"
SECTION = "6"
NEW_QUIZ_NAME = "중간퀴즈"
BACKUP_QUIZ_NAME = "퀴즈_backup_20260410"


QUESTIONS = [
    {"number": 1, "name": "배열포인터 중간퀴즈 개정 01번", "mark": "2"},
    {"number": 2, "name": "배열포인터 중간퀴즈 개정 02번", "mark": "2"},
    {"number": 3, "name": "배열포인터 중간퀴즈 개정 03번", "mark": "2"},
    {"number": 4, "name": "배열포인터 중간퀴즈 개정 04번", "mark": "2"},
    {"number": 5, "name": "배열포인터 중간퀴즈 개정 05번", "mark": "2"},
    {"number": 6, "name": "배열포인터 중간퀴즈 개정 06번", "mark": "2"},
    {"number": 7, "name": "배열포인터 중간퀴즈 개정 07번", "mark": "2"},
    {"number": 8, "name": "배열포인터 중간퀴즈 개정 08번", "mark": "2"},
    {"number": 9, "name": "배열포인터 중간퀴즈 개정 09번", "mark": "2"},
    {"number": 10, "name": "배열포인터 중간퀴즈 개정 10번", "mark": "2"},
    {"number": 11, "name": "배열포인터 중간퀴즈 개정 11번", "mark": "8"},
    {"number": 12, "name": "배열포인터 중간퀴즈 개정 12번", "mark": "8"},
    {"number": 13, "name": "배열포인터 중간퀴즈 개정 13번", "mark": "9"},
    {"number": 14, "name": "배열포인터 중간퀴즈 개정 14번", "mark": "8"},
    {"number": 15, "name": "배열포인터 중간퀴즈 개정 15번", "mark": "10"},
    {"number": 16, "name": "배열포인터 중간퀴즈 개정 16번", "mark": "12"},
    {"number": 17, "name": "배열포인터 중간퀴즈 개정 17번", "mark": "12"},
    {"number": 18, "name": "배열포인터 중간퀴즈 개정 18번", "mark": "13"},
    {"number": 19, "name": "배열포인터 중간퀴즈 개정 19번", "mark": "12"},
    {"number": 20, "name": "배열포인터 중간퀴즈 개정 20번", "mark": "13"},
]


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


def wait_until(predicate, timeout: float = 25.0, interval: float = 0.5) -> None:
    deadline = time.time() + timeout
    while time.time() < deadline:
        if predicate():
            return
        time.sleep(interval)
    raise RuntimeError("Timed out waiting for Safari/eCampus state.")


def p(text: str) -> str:
    return f"<p>{html.escape(text)}</p>"


def code_block(code: str) -> str:
    return f"<pre><code>{html.escape(code)}</code></pre>"


def ul(items: list[str]) -> str:
    return "<ul>" + "".join(f"<li>{html.escape(item)}</li>" for item in items) + "</ul>"


def html_for_question(number: int) -> str:
    if number == 1:
        return p("`int *p;`에서 `p`가 저장하는 것은 무엇인가?")
    if number == 2:
        return p("`&x`의 의미를 쓰시오.")
    if number == 3:
        return p("`*p`의 의미를 쓰시오.")
    if number == 4:
        return p("`int *p1, p2;` 선언에서 포인터 변수 이름만 쓰시오.")
    if number == 5:
        return p("배열 이름 `a`가 가리키는 주소를 배열표기식을 이용하여 쓰시오.")
    if number == 6:
        return p("`a+1`은 무엇을 의미하는지 배열표기식을 이용하여 쓰시오.")
    if number == 7:
        return p("`a[2]`와 같은 의미를 가지는 포인터 표기식을 이용하여 쓰시오.")
    if number == 8:
        return (
            p("다음 코드를 보고 물음에 답하시오.")
            + code_block(
                "void swap_by_value(int x, int y)\n"
                "{\n"
                "    int temp = x;\n"
                "    x = y;\n"
                "    y = temp;\n"
                "}\n\n"
                "void swap_by_address(int *px, int *py)\n"
                "{\n"
                "    int temp = *px;\n"
                "    *px = *py;\n"
                "    *py = temp;\n"
                "}\n"
            )
            + p("`int a = 10, b = 20;`일 때, `swap_by_value(a, b);` 호출 직후 `a`, `b`의 값을 쓰시오.")
        )
    if number == 9:
        return (
            p("다음 코드를 보고 물음에 답하시오.")
            + code_block(
                "void swap_by_value(int x, int y)\n"
                "{\n"
                "    int temp = x;\n"
                "    x = y;\n"
                "    y = temp;\n"
                "}\n\n"
                "void swap_by_address(int *px, int *py)\n"
                "{\n"
                "    int temp = *px;\n"
                "    *px = *py;\n"
                "    *py = temp;\n"
                "}\n"
            )
            + p("`int a = 10, b = 20;`일 때, `swap_by_address(&a, &b);` 호출 직후 `a`, `b`의 값을 쓰시오.")
        )
    if number == 10:
        return p("`swap_by_value(a, b);`와 `swap_by_address(&a, &b);`의 결과가 다른 이유를 짧게 쓰시오.")
    if number == 11:
        return (
            p("다음 코드의 실행 결과를 쓰시오.")
            + code_block(
                "#include <stdio.h>\n\n"
                "int main(void)\n"
                "{\n"
                "    int a[] = {10, 20, 30, 40};\n"
                "    int *p = a;\n\n"
                "    printf(\"%d\\n\", *p);\n"
                "    printf(\"%d\\n\", *(p + 2));\n"
                "    printf(\"%d\\n\", p[3]);\n"
                "    return 0;\n"
                "}\n"
            )
        )
    if number == 12:
        return (
            p("다음 코드의 실행 결과를 쓰시오.")
            + code_block(
                "#include <stdio.h>\n\n"
                "int main(void)\n"
                "{\n"
                "    int a[] = {10, 20, 30};\n"
                "    int *p = a;\n\n"
                "    (*p)++;\n"
                "    printf(\"%d %d\\n\", a[0], *p);\n\n"
                "    p++;\n"
                "    printf(\"%d %d\\n\", *p, p[1]);\n\n"
                "    return 0;\n"
                "}\n"
            )
        )
    if number == 13:
        return (
            p("다음 코드의 실행 결과를 쓰시오.")
            + code_block(
                "#include <stdio.h>\n\n"
                "int main(void)\n"
                "{\n"
                "    int a[2][3] = {\n"
                "        {1, 2, 3},\n"
                "        {4, 5, 6}\n"
                "    };\n\n"
                "    printf(\"%d\\n\", a[0][1]);\n"
                "    printf(\"%d\\n\", *(&a[0][0] + 4));\n"
                "    printf(\"%d\\n\", a[1][2]);\n"
                "    printf(\"%d\\n\", *(&a[0][0] + 1));\n"
                "    return 0;\n"
                "}\n"
            )
        )
    if number == 14:
        return (
            p("다음 함수를 완성하시오.")
            + code_block(
                "int sum_array(const int arr[], int n)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + p("조건:")
            + ul([
                "배열 원소의 합을 반환할 것",
                "배열은 수정하지 않을 것",
                "채점 구조 예시: 누적 변수 선언 및 초기화 2점, 반복문 4점, 합 반환 2점",
            ])
        )
    if number == 15:
        return (
            p("다음 함수를 완성하시오.")
            + code_block(
                "void find_min_max(const int arr[], int n, int *min, int *max)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + p("조건:")
            + ul([
                "최소값은 `*min`, 최대값은 `*max`에 저장할 것",
                "배열 원소는 1개 이상이라고 가정",
                "채점 구조 예시: 초기값 설정 2점, 최소값 갱신 4점, 최대값 갱신 4점",
            ])
        )
    if number == 16:
        return (
            p("다음 함수를 완성하시오.")
            + code_block(
                "void reverse_array(int arr[], int n)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + p("조건:")
            + ul([
                "원본 배열 자체가 뒤집혀야 함",
                "보조 배열 없이 구현할 것",
                "예: `{10,20,30,40,50}` -> `{50,40,30,20,10}`",
                "채점 구조 예시: 양끝 교환 4점, 반복 범위 4점, 실제 교환 완성 4점",
            ])
        )
    if number == 17:
        return (
            p("정수 점수 배열 `scores[]`와 등수를 저장할 배열 `rank[]`가 주어졌을 때, 정렬하지 않고 각 점수의 등수를 계산하는 함수를 작성하시오.")
            + code_block(
                "void calculate_rank(const int scores[], int rank[], int n)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + p("조건:")
            + ul([
                "자기보다 큰 점수의 개수를 세어 등수를 계산할 것",
                "가장 높은 점수는 1등",
                "`scores[i]`는 i번째 학생의 점수이다.",
                "`rank[i]`는 i번째 학생의 등수를 저장하는 배열이다.",
                "같은 점수는 같은 등수로 처리할 것",
                "예: `scores = {88, 95, 72, 90}`, `rank = {3, 1, 4, 2}`",
            ])
        )
    if number == 18:
        return (
            p("배열에서 같은 값이 연속으로 가장 길게 나온 구간의 길이와 그 값을 구하는 함수를 작성하시오.")
            + code_block(
                "void find_longest_run(const int arr[], int n, int *bestValue, int *bestLen)\n"
                "{\n"
                "    int currentLen = 1;\n"
                "    *bestLen = 1;\n"
                "    *bestValue = arr[0];\n\n"
                "    /* 여기에 나머지 코드 작성 */\n"
                "}\n"
            )
            + p("조건:")
            + ul([
                "예: `{1,1,2,2,2,3,3}`이면 값 `2`, 길이 `3`",
                "결과는 출력 매개변수로 저장할 것",
                "가장 긴 구간이 여러 개이면, 먼저 등장한 구간의 값을 선택할 것",
            ])
        )
    if number == 19:
        return (
            p("정수 배열에서 연속된 부분배열 중 합이 가장 큰 구간을 찾아, 그 합과 시작/끝 인덱스를 함께 구하는 함수를 작성하시오.")
            + code_block(
                "void find_max_subarray(const int arr[], int n, int *maxSum, int *startIndex, int *endIndex)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + p("조건:")
            + ul([
                "연속된 부분배열만 인정한다.",
                "최대 합은 `*maxSum`에 저장할 것",
                "시작 위치는 `*startIndex`, 끝 위치는 `*endIndex`에 저장할 것",
                "완전탐색 방식으로 작성해도 된다.",
                "최대 합이 같은 구간이 여러 개이면, 시작 인덱스가 더 작은 구간을 선택할 것",
            ])
        )
    if number == 20:
        return (
            p("정수 배열을 선택 정렬(selection sort) 방식으로 내림차순 정렬하는 함수를 작성하시오.")
            + p("선택 정렬 설명:")
            + ul([
                "각 단계에서 가장 큰 값을 찾아 앞쪽으로 보내는 정렬 방식이다.",
                "예를 들어 0번 자리에 들어갈 가장 큰 값을 먼저 찾고, 그다음 1번 자리에 들어갈 다음 큰 값을 찾는 식으로 진행한다.",
            ])
            + code_block(
                "void selection_sort_desc(int arr[], int n)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + p("조건:")
            + ul([
                "가장 큰 값을 앞쪽으로 보내는 방식으로 정렬할 것",
                "보조 배열 없이 원본 배열 자체를 정렬할 것",
                "같은 값이 여러 개 있으면, 내림차순 조건만 만족하면 된다.",
                "예: `{40, 90, 15, 72}` -> `{90, 72, 40, 15}`",
            ])
        )
    raise ValueError(number)


def ensure_form_loaded() -> None:
    wait_until(
        lambda: safari_js(
            'JSON.stringify({name:!!document.getElementById("id_name"),submit:!!document.getElementById("id_submitbutton"),section:!!document.getElementById("id_section")})'
        )
        == '{"name":true,"submit":true,"section":true}'
    )


def ensure_question_form_loaded() -> None:
    wait_until(
        lambda: safari_js(
            'JSON.stringify({name:!!document.getElementById("id_name"),qtext:!!document.getElementById("id_questiontext"),mark:!!document.getElementById("id_defaultmark"),submit:!!document.getElementById("id_submitbutton")})'
        )
        == '{"name":true,"qtext":true,"mark":true,"submit":true}'
    )


def set_editor_js(target_id_expr: str, html_var: str) -> str:
    return (
        f'var ta={target_id_expr};'
        'if(ta){'
        f'  ta.value={html_var};'
        '  var ed=ta.parentElement && ta.parentElement.querySelector(".editor_atto_content");'
        f'  if(ed){{ed.innerHTML={html_var};ed.dispatchEvent(new Event("input",{{bubbles:true}}));ed.dispatchEvent(new Event("change",{{bubbles:true}}));}}'
        '}'
    )


def rename_old_quiz() -> None:
    safari_open(f"https://ecampus.kookmin.ac.kr/course/modedit.php?update={OLD_QUIZ_CMID}&return=1")
    wait_until(lambda: f"update={OLD_QUIZ_CMID}" in safari_url())
    ensure_form_loaded()
    js = (
        "(function(){"
        f'var newName={json.dumps(BACKUP_QUIZ_NAME, ensure_ascii=False)};'
        'document.getElementById("id_name").value=newName;'
        'document.getElementById("id_submitbutton").click();'
        'return "submitted";'
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/mod/quiz/view.php" in safari_url() or "/course/view.php" in safari_url(), timeout=30)


def create_new_quiz() -> str:
    safari_open(f"https://ecampus.kookmin.ac.kr/course/modedit.php?course={COURSE_ID}&add=quiz&section={SECTION}")
    wait_until(lambda: "add=quiz" in safari_url())
    ensure_form_loaded()
    js = (
        "(function(){"
        f'var quizName={json.dumps(NEW_QUIZ_NAME, ensure_ascii=False)};'
        'document.getElementById("id_name").value=quizName;'
        'document.getElementById("id_section").value=' + json.dumps(SECTION) + ';'
        'document.getElementById("id_timeopen_enabled").checked=true;'
        'document.getElementById("id_timeopen_year").value="2026";'
        'document.getElementById("id_timeopen_month").value="4";'
        'document.getElementById("id_timeopen_day").value="15";'
        'document.getElementById("id_timeopen_hour").value="9";'
        'document.getElementById("id_timeopen_minute").value="5";'
        'document.getElementById("id_timeclose_enabled").checked=true;'
        'document.getElementById("id_timeclose_year").value="2026";'
        'document.getElementById("id_timeclose_month").value="4";'
        'document.getElementById("id_timeclose_day").value="15";'
        'document.getElementById("id_timeclose_hour").value="10";'
        'document.getElementById("id_timeclose_minute").value="40";'
        'document.getElementById("id_timelimit_enabled").checked=true;'
        'document.getElementById("id_timelimit_number").value="75";'
        'document.getElementById("id_timelimit_timeunit").value="60";'
        'document.getElementById("id_visible").value="0";'
        'document.getElementById("id_questionsperpage").value="1";'
        'document.getElementById("id_submitbutton").click();'
        'return "submitted";'
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/mod/quiz/view.php" in safari_url() or "/course/view.php" in safari_url(), timeout=30)
    url = safari_url()
    m = re.search(r"[?&]id=(\d+)", url)
    if not m:
        raise RuntimeError(f"Could not determine new quiz cmid from URL: {url}")
    return m.group(1)


def page_url(question_type: str) -> str:
    return (
        "https://ecampus.kookmin.ac.kr/question/question.php"
        f"?courseid={COURSE_ID}&sesskey={SESSKEY}&qtype={question_type}"
        f"&returnurl=%2Fquestion%2Fedit.php%3Fcourseid%3D{COURSE_ID}&category={CATEGORY}"
    )


def submit_essay(question: dict) -> None:
    safari_open(page_url("essay"))
    wait_until(lambda: "qtype=essay" in safari_url())
    ensure_question_form_loaded()
    qtext_html = html_for_question(question["number"])
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        f"var qhtml={json.dumps(qtext_html, ensure_ascii=False)};"
        'document.getElementById("id_name").value=q.name;'
        + set_editor_js('document.getElementById("id_questiontext")', "qhtml")
        + 'document.getElementById("id_defaultmark").value=q.mark;'
        'var f=document.forms[0]; var b=document.getElementById("id_submitbutton");'
        'if(f && f.requestSubmit && b){f.requestSubmit(b); return "requested";}'
        'if(f){f.submit(); return "submitted";}'
        'return "noform";'
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/question/edit.php" in safari_url(), timeout=30)
    time.sleep(0.7)


def get_existing_qbank_ids(prefix: str) -> dict[str, int]:
    merged: dict[str, int] = {}
    for qpage in range(0, 5):
        if qpage == 0:
            safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?courseid={COURSE_ID}")
        else:
            safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?courseid={COURSE_ID}&qpage={qpage}")
        wait_until(lambda: "/question/edit.php" in safari_url())
        time.sleep(0.6)
        raw = safari_js(
            f"""
(() => {{
  const result = {{}};
  for (const tr of document.querySelectorAll('tr')) {{
    const rowText = (tr.innerText || "").trim();
    if (!rowText.includes({json.dumps(prefix, ensure_ascii=False)})) continue;
    const nameEl = tr.querySelector(".questionname");
    const checkbox = tr.querySelector('input[id^="checkq"]');
    const name = nameEl ? (nameEl.textContent || "").trim() : "";
    const m = checkbox ? checkbox.id.match(/checkq(\\d+)/) : null;
    if (name && m) {{
      const qid = parseInt(m[1], 10);
      if (!(name in result) || qid > result[name]) {{
        result[name] = qid;
      }}
    }}
  }}
  return JSON.stringify(result);
}})();
"""
        )
        data = json.loads(raw)
        for name, qid in data.items():
            if name not in merged or qid > merged[name]:
                merged[name] = qid
    return merged


def attach_questions_to_quiz(cmid: str, qids: list[int]) -> None:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={cmid}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    js = (
        "(function(){"
        f"var qids={json.dumps(qids)};"
        f"var sesskey={json.dumps(SESSKEY)};"
        f"var cmid={json.dumps(cmid)};"
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


def verify_quiz(cmid: str) -> dict:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={cmid}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    return json.loads(
        safari_js(
            """
(() => {
  const text = document.body.innerText || "";
  return JSON.stringify({
    problemCountLine: (text.match(/출제 문제 수\\s*:?\\s*\\d+/) || [""])[0],
    totalLine: (text.match(/총점\\s*:?\\s*[0-9.]+/) || [""])[0],
    count: (text.match(/배열포인터 중간퀴즈 개정/g) || []).length
  });
})();
"""
        )
    )


def main() -> int:
    print("Renaming existing quiz to backup ...", flush=True)
    rename_old_quiz()

    print("Creating new clean quiz ...", flush=True)
    new_cmid = create_new_quiz()
    print(f"new_cmid={new_cmid}", flush=True)

    existing = get_existing_qbank_ids("배열포인터 중간퀴즈 개정")
    for q in QUESTIONS:
        if q["name"] in existing:
            print(f"Already exists in bank: {q['name']} -> {existing[q['name']]}", flush=True)
            continue
        print(f"Registering {q['name']} ...", flush=True)
        submit_essay(q)

    existing = get_existing_qbank_ids("배열포인터 중간퀴즈 개정")
    attach_ids = [existing[q["name"]] for q in QUESTIONS]
    print(f"Attaching {len(attach_ids)} questions ...", flush=True)
    attach_questions_to_quiz(new_cmid, attach_ids)

    result = verify_quiz(new_cmid)
    print(json.dumps(result, ensure_ascii=False, indent=2), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
