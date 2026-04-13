# C 언어 중간퀴즈 채점기준안

- 기준 버전: eCampus `중간퀴즈` 현재 편집 화면 기준
- 문항 수: 16문항
- 총점: 100점
- 범위: 배열, 포인터, 배열과 포인터의 관계, 함수 매개변수, 2차원 배열 기초, 배열 응용 알고리즘

## 채점 공통 원칙

- 짧은 단답형은 의미가 같으면 정답으로 인정한다.
- 변수명, 반복문 형태, 임시 변수 이름은 달라도 동작과 핵심 알고리즘이 맞으면 정답으로 인정한다.
- 구현 문제는 제시한 기준에 따라 부분점수를 부여한다.
- 문법 오류가 있더라도 의도가 명확하고 핵심 로직이 맞으면 부분점수를 준다.
- 출력 문제는 줄별로 독립 채점한다.

---

## 1번. `int *p;`에서 `p`가 저장하는 것은 무엇인가? (2점)

- 정답 예시: `주소`, `메모리 주소`, `어떤 변수의 주소`
- 채점:
  - 2점: 정답
  - 0점: 오답

## 2번. `int x;`가 선언되어 있을 때, `&x`의 의미를 쓰시오. (2점)

- 정답 예시: `x의 주소`, `변수 x의 메모리 주소`
- 채점:
  - 2점: 정답
  - 0점: 오답

## 3번. `int *p;`가 선언되어 있을 때, `*p`의 의미를 쓰시오. (2점)

- 정답 예시: `p가 가리키는 곳의 값`, `p가 가리키는 주소에 저장된 값`
- 채점:
  - 2점: 정답
  - 0점: 오답

## 4번. `int *p1, p2;` 선언에서 포인터 변수 이름만 쓰시오. (2점)

- 정답: `p1`
- 채점:
  - 2점: `p1`
  - 0점: 그 외

## 5번. 배열 이름 `a`가 가리키는 주소를 배열표기식으로 쓰시오. (2점)

- 정답: `&a[0]`
- 채점:
  - 2점: `&a[0]`
  - 0점: 그 외

## 6번. `a+1`이 의미하는 것을 배열표기식으로 쓰시오. (2점)

- 정답: `&a[1]`
- 채점:
  - 2점: `&a[1]`
  - 0점: 그 외

## 7번. `a[2]`와 같은 의미의 포인터 표기식을 쓰시오. (2점)

- 정답: `*(a+2)`
- 채점:
  - 2점: `*(a+2)`
  - 0점: 그 외

## 8번. `swap_by_value(a, b);` 호출 직후 `a`, `b`의 값을 쓰시오. (4점)

- 정답: `a = 10`, `b = 20`
- 채점:
  - 4점: 두 값을 모두 맞게 씀
  - 0점: 하나라도 틀림

## 9번. 실행 결과 쓰기 1 (8점)

```c
int a[] = {10, 20, 30, 40};
int *p = a;
printf("%d\n", *p);
printf("%d\n", *(p + 2));
printf("%d\n", p[3]);
```

- 정답:
  - 첫째 줄: `10`
  - 둘째 줄: `30`
  - 셋째 줄: `40`
- 채점:
  - 첫째 줄 2점
  - 둘째 줄 3점
  - 셋째 줄 3점

## 10번. 실행 결과 쓰기 2 (8점)

```c
int a[] = {10, 20, 30};
int *p = a;
(*p)++;
printf("%d %d\n", a[0], *p);
p++;
printf("%d %d\n", *p, p[1]);
```

- 정답:
  - 첫째 줄: `11 11`
  - 둘째 줄: `20 30`
- 채점:
  - 첫째 줄 4점
  - 둘째 줄 4점

## 11번. 2차원 배열 실행 결과 쓰기 (8점)

```c
int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
printf("%d\n", a[0][1]);
printf("%d\n", *(&a[0][0] + 4));
printf("%d\n", a[1][2]);
printf("%d\n", *(&a[0][0] + 1));
```

- 정답:
  - 첫째 줄: `2`
  - 둘째 줄: `5`
  - 셋째 줄: `6`
  - 넷째 줄: `2`
- 채점:
  - 각 줄 2점

## 12번. `sum_array` 함수 작성 (8점)

```c
int sum_array(const int arr[], int n)
{
    /* 여기에 코드 작성 */
}
```

- 모범 답안 예시:

```c
int sum_array(const int arr[], int n)
{
    int sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
```

- 채점:
  - 2점: 누적 변수 선언 및 초기화
  - 4점: `0`부터 `n-1`까지 순회하며 합 누적
  - 2점: 합 반환

## 13번. `find_min_max` 함수 작성 (12점)

```c
void find_min_max(const int arr[], int n, int *min, int *max)
{
    /* 여기에 코드 작성 */
}
```

- 모범 답안 예시:

```c
void find_min_max(const int arr[], int n, int *min, int *max)
{
    int i;
    *min = arr[0];
    *max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}
```

- 채점:
  - 3점: 초기값을 첫 원소로 설정
  - 3점: 반복문 범위가 적절함 (`i=1`부터 시작하거나 동등한 방식)
  - 3점: 최소값 비교/갱신
  - 3점: 최대값 비교/갱신

## 14번. 가장 긴 연속 구간 찾기 (14점)

```c
void find_longest_run(const int arr[], int n, int *bestValue, int *bestLen)
{
    int currentLen = 1;
    *bestLen = 1;
    *bestValue = arr[0];

    /* 여기에 나머지 코드 작성 */
}
```

- 의도:
  - 같은 값이 연속될 때 현재 구간 길이를 늘린다.
  - 값이 바뀌면 현재 구간을 종료하고 최적 구간을 갱신할지 판단한다.
  - 마지막 구간도 반드시 확인해야 한다.
  - 길이가 같으면 먼저 나온 구간 유지

- 모범 답안 예시:

```c
void find_longest_run(const int arr[], int n, int *bestValue, int *bestLen)
{
    int currentLen = 1;
    int i;

    *bestLen = 1;
    *bestValue = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentLen++;
        } else {
            if (currentLen > *bestLen) {
                *bestLen = currentLen;
                *bestValue = arr[i - 1];
            }
            currentLen = 1;
        }
    }

    if (currentLen > *bestLen) {
        *bestLen = currentLen;
        *bestValue = arr[n - 1];
    }
}
```

- 채점:
  - 4점: 현재 구간 길이 추적
  - 4점: 값이 바뀔 때 최적 구간 갱신
  - 2점: 구간 초기화(`currentLen = 1`)
  - 4점: 마지막 구간 처리 및 동률 조건 유지

## 15번. 최대 부분배열의 합과 위치 구하기 (12점)

```c
void find_max_subarray(const int arr[], int n, int *maxSum, int *startIndex, int *endIndex)
{
    /* 여기에 코드 작성 */
}
```

- 의도:
  - 모든 시작점과 끝점을 검사하는 완전탐색 허용
  - 각 구간 합을 계산하고 최댓값이면 갱신
  - 합이 같으면 시작 인덱스가 작은 구간 유지

- 모범 답안 예시:

```c
void find_max_subarray(const int arr[], int n, int *maxSum, int *startIndex, int *endIndex)
{
    int i, j;

    *maxSum = arr[0];
    *startIndex = 0;
    *endIndex = 0;

    for (i = 0; i < n; i++) {
        int sum = 0;
        for (j = i; j < n; j++) {
            sum += arr[j];
            if (sum > *maxSum) {
                *maxSum = sum;
                *startIndex = i;
                *endIndex = j;
            }
        }
    }
}
```

- 채점:
  - 3점: 시작점/끝점 이중 반복
  - 3점: 각 구간의 합 계산
  - 3점: 최대 합 갱신
  - 3점: 시작/끝 인덱스 저장 및 동률 조건에 어긋나지 않음

## 16번. 선택 정렬 내림차순 (12점)

```c
void selection_sort_desc(int arr[], int n)
{
    /* 여기에 코드 작성 */
}
```

- 모범 답안 예시:

```c
void selection_sort_desc(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}
```

- 채점:
  - 3점: 바깥 반복으로 각 자리를 확정
  - 3점: 안쪽 반복으로 최대값 위치 찾기
  - 3점: 교환 로직 구현
  - 3점: 최종적으로 내림차순 정렬 완성

---

## 총평 기준

- 1~8번: 포인터/배열 기본 개념을 정확히 이해했는지 확인
- 9~11번: 포인터 연산과 배열 해석을 코드 실행 결과로 읽을 수 있는지 확인
- 12~13번: 기본 구현 능력 확인
- 14~16번: 배열 순회 알고리즘을 응용 문제로 확장할 수 있는지 확인
