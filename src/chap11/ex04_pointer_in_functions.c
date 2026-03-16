#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
[ex04] 포인터/배열/출력 매개변수
------------------------------------------------------------
핵심
1) 값 전달은 복사본이라 원본이 바뀌지 않는다.
2) 주소 전달은 원본을 직접 수정한다. (swap 성공)
3) 배열은 함수로 전달 시 "첫 원소의 주소"가 전달된다.
4) 여러 값을 반환해야 하면 포인터 매개변수(out)를 사용한다.
5) 읽기 전용으로 쓸 때는 const 포인터 매개변수를 사용한다.
------------------------------------------------------------
슬라이드 키워드
- call by value / reference
- 포인터와 함수
- 배열 매개변수
- out 파라미터
- const 포인터
------------------------------------------------------------
*/

void swap_by_value(int x, int y)
{
    // 값 복사본만 바뀌므로 원본에는 영향 없음
    int tmp = x; x = y; y = tmp;
}

void swap_by_address(int *px, int *py)
{
    // 포인터가 원본을 가리키므로 실제 원본이 바뀜
    int tmp = *px; *px = *py; *py = tmp;
}

void set_array(int b[], int n)
{
    // 배열은 첫 원소 주소가 전달되므로 원본이 직접 변경된다.
    for (int i = 0; i < n; i++) {
        b[i] = (i + 1) * 10;
    }
}

int sum_array(const int b[], int n)
{
    // const 포인터 매개변수: 함수 안에서 배열 값을 변경하지 않겠다는 뜻
    int sum = 0;
    for (int i = 0; i < n; i++) sum += b[i];
    return sum;
}

// 직선 y = ax + b의 a, b를 out 파라미터로 반환
int get_line_parameter(int x1, int y1, int x2, int y2, float *slope, float *yintercept)
{
    if (x1 == x2) return -1;
    *slope = (float)(y2 - y1) / (float)(x2 - x1);
    *yintercept = y1 - (*slope) * x1;
    return 0;
}

// 배열에 센서 데이터를 채우는 예제(미니 프로젝트)
void get_sensor_data(double *p)
{
    for (int i = 0; i < 3; i++) {
        p[i] = rand() % 100; // 0~99
    }
}

int main(void)
{
    // (1) swap 비교
    int a = 100, b = 200;
    printf("a=%d b=%d\n", a, b);
    swap_by_value(a, b);
    printf("after value : a=%d b=%d\n", a, b);

    swap_by_address(&a, &b);
    printf("after address: a=%d b=%d\n\n", a, b);

    // (2) 배열 전달
    int arr[3] = {1, 2, 3};
    printf("before: %d %d %d\n", arr[0], arr[1], arr[2]);
    set_array(arr, 3);
    printf("after : %d %d %d\n\n", arr[0], arr[1], arr[2]);
    printf("sum   : %d\\n\\n", sum_array(arr, 3));

    // (3) out 파라미터
    float s, y;
    if (get_line_parameter(3, 3, 6, 6, &s, &y) == -1) {
        printf("수직선이라 기울기 없음\n");
    } else {
        printf("slope = %.2f, y-intercept = %.2f\n", s, y);
    }

    // (4) 센서 데이터 채우기
    srand((unsigned int)time(NULL));
    double sensor[3];
    get_sensor_data(sensor);
    printf(\"sensor: %.0f %.0f %.0f\\n\", sensor[0], sensor[1], sensor[2]);

    return 0;
}
