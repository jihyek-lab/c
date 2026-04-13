#!/usr/bin/env python3
import html
import json
import subprocess
import sys
import time


COURSE_ID = "83169"
SESSKEY = "nalAOrEc44"
CATEGORY = "118165,2202824"
QUIZ_CMID = "1886213"


QUESTIONS = [
    {"number": 1, "qtype": "essay", "name": "배열포인터 중간퀴즈 01번", "mark": "8"},
    {"number": 2, "qtype": "essay", "name": "배열포인터 중간퀴즈 02번", "mark": "6"},
    {"number": 3, "qtype": "essay", "name": "배열포인터 중간퀴즈 03번", "mark": "6"},
    {"number": 4, "qtype": "essay", "name": "배열포인터 중간퀴즈 04번", "mark": "8"},
    {"number": 5, "qtype": "essay", "name": "배열포인터 중간퀴즈 05번", "mark": "8"},
    {"number": 6, "qtype": "essay", "name": "배열포인터 중간퀴즈 06번", "mark": "9"},
    {"number": 7, "qtype": "essay", "name": "배열포인터 중간퀴즈 07번", "mark": "8"},
    {"number": 8, "qtype": "essay", "name": "배열포인터 중간퀴즈 08번", "mark": "10"},
    {"number": 9, "qtype": "essay", "name": "배열포인터 중간퀴즈 09번", "mark": "12"},
    {"number": 10, "qtype": "essay", "name": "배열포인터 중간퀴즈 10번", "mark": "12"},
    {"number": 11, "qtype": "essay", "name": "배열포인터 중간퀴즈 11번", "mark": "13"},
    {"number": 12, "qtype": "essay", "name": "배열포인터 중간퀴즈 12번", "mark": "12"},
    {"number": 13, "qtype": "essay", "name": "배열포인터 중간퀴즈 13번", "mark": "13"},
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


def wait_until(predicate, timeout: float = 20.0, interval: float = 0.5) -> None:
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
        return (
            p("다음 물음에 한두 단어 또는 짧은 구로 답하시오.")
            + ul([
                "`int *p;`에서 `p`가 저장하는 것은 무엇인가? (2점)",
                "`&x`의 의미를 쓰시오. (2점)",
                "`*p`의 의미를 쓰시오. (2점)",
                "`int *p1, p2;` 선언에서 포인터 변수 이름만 쓰시오. (2점)",
            ])
        )
    if number == 2:
        return (
            p("다음 물음에 짧게 답하시오.")
            + ul([
                "배열 이름 `a`가 가리키는 주소를 배열표기식을 이용하여 쓰시오. (2점)",
                "`a+1`은 무엇을 의미하는지 배열표기식을 이용하여 쓰시오. (2점)",
                "`a[2]`와 같은 의미를 가지는 포인터 표기식을 이용하여 쓰시오. (2점)",
            ])
        )
    if number == 3:
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
            + p("`int a = 10, b = 20;`일 때, 다음 물음에 답하시오.")
            + ul([
                "`swap_by_value(a, b);` 호출 직후 `a`, `b`의 값을 쓰시오. (2점)",
                "이어서 `swap_by_address(&a, &b);`를 호출한 뒤 `a`, `b`의 값을 쓰시오. (2점)",
                "두 결과가 다른 이유를 짧게 쓰시오. (2점)",
            ])
        )
    if number == 4:
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
    if number == 5:
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
    if number == 6:
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
    if number == 7:
        return (
            p("다음 함수를 완성하시오.")
            + code_block(
                "int sum_array(const int arr[], int n)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + ul([
                "배열 원소의 합을 반환할 것",
                "배열은 수정하지 않을 것",
            ])
        )
    if number == 8:
        return (
            p("다음 함수를 완성하시오.")
            + code_block(
                "void find_min_max(const int arr[], int n, int *min, int *max)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + ul([
                "최소값은 `*min`, 최대값은 `*max`에 저장할 것",
                "배열 원소는 1개 이상이라고 가정",
                "최소값이나 최대값이 여러 번 나와도, 그 값 자체만 올바르게 저장하면 된다.",
            ])
        )
    if number == 9:
        return (
            p("다음 함수를 완성하시오.")
            + code_block(
                "void reverse_array(int arr[], int n)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + ul([
                "원본 배열 자체가 뒤집혀야 함",
                "보조 배열 없이 구현할 것",
                "예: `{10,20,30,40,50}` -> `{50,40,30,20,10}`",
            ])
        )
    if number == 10:
        return (
            p("정수 점수 배열 `scores[]`와 등수를 저장할 배열 `rank[]`가 주어졌을 때, 정렬하지 않고 각 점수의 등수를 계산하는 함수를 작성하시오.")
            + code_block(
                "void calculate_rank(const int scores[], int rank[], int n)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + ul([
                "자기보다 큰 점수의 개수를 세어 등수를 계산할 것",
                "가장 높은 점수는 1등",
                "`scores[i]`는 i번째 학생의 점수이다.",
                "`rank[i]`는 i번째 학생의 등수를 저장하는 배열이다.",
                "같은 점수는 같은 등수로 처리할 것",
                "예: `scores = {88, 95, 72, 90}`, `rank = {3, 1, 4, 2}`",
            ])
        )
    if number == 11:
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
            + ul([
                "예: `{1,1,2,2,2,3,3}`이면 값 `2`, 길이 `3`",
                "결과는 출력 매개변수로 저장할 것",
                "가장 긴 구간이 여러 개이면, 먼저 등장한 구간의 값을 선택할 것",
            ])
        )
    if number == 12:
        return (
            p("정수 배열에서 연속된 부분배열 중 합이 가장 큰 구간을 찾아, 그 합과 시작/끝 인덱스를 함께 구하는 함수를 작성하시오.")
            + code_block(
                "void find_max_subarray(const int arr[], int n, int *maxSum, int *startIndex, int *endIndex)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + ul([
                "연속된 부분배열만 인정한다.",
                "최대 합은 `*maxSum`에 저장할 것",
                "시작 위치는 `*startIndex`, 끝 위치는 `*endIndex`에 저장할 것",
                "완전탐색 방식으로 작성해도 된다.",
                "최대 합이 같은 구간이 여러 개이면, 시작 인덱스가 더 작은 구간을 선택할 것",
                "예: `arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}`에서 최대 합은 `6`",
            ])
        )
    if number == 13:
        return (
            p("정수 배열을 선택 정렬(selection sort) 방식으로 내림차순 정렬하는 함수를 작성하시오.")
            + p("선택 정렬 설명: 각 단계에서 가장 큰 값을 찾아 앞쪽으로 보내는 정렬 방식이다. 예를 들어 0번 자리에 들어갈 가장 큰 값을 먼저 찾고, 그다음 1번 자리에 들어갈 다음 큰 값을 찾는 식으로 진행한다.")
            + code_block(
                "void selection_sort_desc(int arr[], int n)\n"
                "{\n"
                "    /* 여기에 코드 작성 */\n"
                "}\n"
            )
            + ul([
                "가장 큰 값을 앞쪽으로 보내는 방식으로 정렬할 것",
                "보조 배열 없이 원본 배열 자체를 정렬할 것",
                "같은 값이 여러 개 있으면, 내림차순 조건만 만족하면 된다.",
                "예: `{40, 90, 15, 72}` -> `{90, 72, 40, 15}`",
            ])
        )
    raise ValueError(number)


def page_url(question_type: str) -> str:
    return (
        "https://ecampus.kookmin.ac.kr/question/question.php"
        f"?courseid={COURSE_ID}&sesskey={SESSKEY}&qtype={question_type}"
        f"&returnurl=%2Fquestion%2Fedit.php%3Fcourseid%3D{COURSE_ID}&category={CATEGORY}"
    )


def ensure_form_loaded(question_type: str) -> None:
    wait_until(lambda: f"qtype={question_type}" in safari_url())
    wait_until(lambda: safari_js('!!document.getElementById("id_name") && !!document.getElementById("id_submitbutton")') == "true")


def set_editor_js(target_id_expr: str, html_var: str) -> str:
    return (
        f'var ta={target_id_expr};'
        'if(ta){'
        f'  ta.value={html_var};'
        '  var ed=ta.parentElement && ta.parentElement.querySelector(".editor_atto_content");'
        f'  if(ed){{ed.innerHTML={html_var};ed.dispatchEvent(new Event("input",{{bubbles:true}}));ed.dispatchEvent(new Event("change",{{bubbles:true}}));}}'
        '}'
    )


def submit_essay(question: dict) -> None:
    safari_open(page_url("essay"))
    ensure_form_loaded("essay")
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


def wait_for_saved() -> None:
    wait_until(lambda: "/question/edit.php" in safari_url())


def submit_question(question: dict) -> None:
    submit_essay(question)
    wait_for_saved()


def get_existing_qbank_ids() -> dict[str, int]:
    merged: dict[str, int] = {}
    for qpage in (0, 1, 2):
        if qpage == 0:
            safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?courseid={COURSE_ID}")
        else:
            safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?courseid={COURSE_ID}&qpage={qpage}")
        wait_until(lambda: "/question/edit.php" in safari_url())
        time.sleep(0.6)
        data = json.loads(
            safari_js(
                """
(() => {
  const result = {};
  for (const tr of document.querySelectorAll('tr')) {
    const rowText = (tr.innerText || "").trim();
    if (!rowText.includes("배열포인터 중간퀴즈")) continue;
    const nameEl = tr.querySelector(".questionname");
    const checkbox = tr.querySelector('input[id^="checkq"]');
    const name = nameEl ? (nameEl.textContent || "").trim() : "";
    const m = checkbox ? checkbox.id.match(/checkq(\\d+)/) : null;
    if (name && m) {
      const qid = parseInt(m[1], 10);
      if (!(name in result) || qid > result[name]) {
        result[name] = qid;
      }
    }
  }
  return JSON.stringify(result);
})();
"""
            )
        )
        for name, qid in data.items():
            if name not in merged or qid > merged[name]:
                merged[name] = qid
    return merged


def get_existing_quiz_names() -> set[str]:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    raw = safari_js(
        """
(() => {
  const text = document.body.innerText || "";
  const names = text
    .split("\\n")
    .map(s => s.trim())
    .filter(s => s.startsWith("배열포인터 중간퀴즈"));
  return JSON.stringify(names);
})();
"""
    )
    try:
        return set(json.loads(raw))
    except Exception:
        return set()


def attach_questions_to_quiz(qids: list[int]) -> None:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    js = (
        "(function(){"
        f"var qids={json.dumps(qids)};"
        f"var sesskey={json.dumps(SESSKEY)};"
        f"var cmid={json.dumps(QUIZ_CMID)};"
        'var form=document.createElement("form");'
        'form.method="POST";'
        'form.action=location.href;'
        'function add(name,value){var i=document.createElement("input");i.type="hidden";i.name=name;i.value=value;form.appendChild(i);}'
        'add("sesskey", sesskey);'
        'add("cmid", cmid);'
        'add("addoneminform", "페이지에 추가");'
        'qids.forEach(function(id){ add("q" + id, "1"); });'
        'document.body.appendChild(form);'
        'form.submit();'
        'return "submitted";'
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url(), timeout=30)


def main() -> int:
    requested_numbers = [q["number"] for q in QUESTIONS]
    if len(sys.argv) > 1:
        requested_numbers = [int(x) for x in sys.argv[1:]]

    selected = [q for q in QUESTIONS if q["number"] in requested_numbers]

    # Register missing questions in question bank
    for q in selected:
        ids = get_existing_qbank_ids()
        if q["name"] in ids:
            print(f"Already exists in bank: {q['name']} -> {ids[q['name']]}")
            continue
        print(f"Registering {q['name']} ...", flush=True)
        submit_question(q)
        time.sleep(0.7)

    ids = get_existing_qbank_ids()
    attach_ids = []
    existing_quiz_names = get_existing_quiz_names()
    for q in selected:
        if q["name"] in existing_quiz_names:
            print(f"Already in quiz: {q['name']}")
            continue
        if q["name"] not in ids:
            raise RuntimeError(f"Question ID not found in bank for {q['name']}")
        attach_ids.append(ids[q["name"]])

    if attach_ids:
        print(f"Attaching qids: {attach_ids}", flush=True)
        attach_questions_to_quiz(attach_ids)
    else:
        print("No new questions to attach.", flush=True)

    print("Done.", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
