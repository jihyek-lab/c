#include <stdio.h>
#include <math.h>

/*
[ex02] 구조체 초기화 + 중첩 구조체
------------------------------------------------------------
파트 A) 초기화 방법
- 중괄호 초기화, 지정 초기화(C99), 구조체 대입

파트 B) 점 거리 계산
- point 구조체로 두 점의 거리를 계산

파트 C) 사각형(중첩 구조체)
- rect 안에 point를 포함한다.
------------------------------------------------------------
슬라이드 키워드
- 구조체 초기화(지정 초기화 포함)
- 중첩 구조체
- 점/사각형 예제
------------------------------------------------------------
*/

struct point {
    int x;
    int y;
};

struct rect {
    struct point p1;
    struct point p2;
};

static double distance(struct point a, struct point b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt((double)(dx * dx + dy * dy));
}

int main(void)
{
    // (A) 다양한 초기화
    struct point p = {1, 2};
    struct point q = {.y = 2, .x = 1}; // C99 지정 초기화
    struct point r = p;                // 구조체 대입(멤버 복사)

    printf("p=(%d,%d) q=(%d,%d) r=(%d,%d)\n\n", p.x, p.y, q.x, q.y, r.x, r.y);

    // (B) 두 점 거리
    struct point a, b;
    printf("점의 좌표를 입력하시오(x y): ");
    scanf("%d %d", &a.x, &a.y);
    printf("점의 좌표를 입력하시오(x y): ");
    scanf("%d %d", &b.x, &b.y);
    printf("거리 = %.6f\n\n", distance(a, b));

    // (C) 사각형 면적/둘레
    struct rect rt; // 중첩 구조체: rect 안에 point 2개
    int w, h, area, peri;
    printf("왼쪽 상단 좌표: ");
    scanf("%d %d", &rt.p1.x, &rt.p1.y);
    printf("오른쪽 하단 좌표: ");
    scanf("%d %d", &rt.p2.x, &rt.p2.y);

    // 꼭짓점 좌표로 너비/높이 계산
    w = rt.p2.x - rt.p1.x;
    h = rt.p2.y - rt.p1.y;
    area = w * h;
    peri = 2 * (w + h);

    printf("면적 = %d, 둘레 = %d\n", area, peri);

    return 0;
}
