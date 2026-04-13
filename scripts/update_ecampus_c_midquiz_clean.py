#!/usr/bin/env python3
import html
import json
import subprocess
import time


QUIZ_CMID = "1886281"
QUESTION_IDS = {
    1: 749344,
    2: 749345,
    3: 749346,
    4: 749347,
    5: 749348,
    6: 749349,
    7: 749350,
    8: 749351,
    9: 749352,
    10: 749353,
    11: 749354,
    12: 749355,
    13: 749356,
    14: 749357,
    15: 749358,
    16: 749359,
    17: 749360,
    18: 749361,
    19: 749362,
    20: 749363,
}


QUESTIONS = [
    {"number": 1, "name": "배열포인터 중간퀴즈 개정 01번", "mark": "2"},
    {"number": 2, "name": "배열포인터 중간퀴즈 개정 02번", "mark": "2"},
    {"number": 3, "name": "배열포인터 중간퀴즈 개정 03번", "mark": "2"},
    {"number": 4, "name": "배열포인터 중간퀴즈 개정 04번", "mark": "2"},
    {"number": 5, "name": "배열포인터 중간퀴즈 개정 05번", "mark": "2"},
    {"number": 6, "name": "배열포인터 중간퀴즈 개정 06번", "mark": "2"},
    {"number": 7, "name": "배열포인터 중간퀴즈 개정 07번", "mark": "2"},
    {"number": 8, "name": "배열포인터 중간퀴즈 개정 08번", "mark": "2"},
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
        return p("`int x;`가 선언되어 있을 때, `&x`의 의미를 쓰시오.")
    if number == 3:
        return p("`int *p;`가 선언되어 있을 때, `*p`의 의미를 쓰시오.")
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
                "예: `arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}`에서 최대 합은 `6`",
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


def edit_url(qid: int) -> str:
    return (
        "https://ecampus.kookmin.ac.kr/question/question.php"
        f"?returnurl=%2Fquestion%2Fedit.php%3Fcmid%3D{QUIZ_CMID}&cmid={QUIZ_CMID}&id={qid}"
    )


def ensure_form_loaded(qid: int) -> None:
    wait_until(lambda: f"id={qid}" in safari_url())
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


def update_question(question: dict) -> None:
    qid = QUESTION_IDS[question["number"]]
    safari_open(edit_url(qid))
    ensure_form_loaded(qid)
    qhtml = html_for_question(question["number"])
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        f"var qhtml={json.dumps(qhtml, ensure_ascii=False)};"
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
    time.sleep(0.8)


def verify_quiz() -> dict:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    return json.loads(
        safari_js(
            """
(() => {
  const text = document.body.innerText || "";
  return JSON.stringify({
    count: (text.match(/배열포인터 중간퀴즈 개정/g) || []).length,
    problemCountLine: (text.match(/출제 문제 수\\s*:?\\s*\\d+/) || [""])[0],
    totalLine: (text.match(/총점\\s*:?\\s*[0-9.]+/) || [""])[0]
  });
})();
"""
        )
    )


def main() -> int:
    for question in QUESTIONS:
        print(f"Updating {question['name']} ...", flush=True)
        update_question(question)
    result = verify_quiz()
    print(json.dumps(result, ensure_ascii=False, indent=2), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
