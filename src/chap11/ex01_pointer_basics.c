#include <stdio.h>

/*
[ex01] 포인터 기본: 주소, 역참조, 같은 포인터의 대상 변경
------------------------------------------------------------
핵심
1) &연산자는 변수의 주소를 얻는다.
2) 포인터는 "주소"를 저장하고, *포인터는 그 주소의 "값"을 읽는다.
3) 같은 포인터라도 가리키는 대상이 바뀌면 출력이 달라진다.
4) 포인터 선언은 한 줄에 여러 개를 쓰면 혼동되므로 주의한다.
   int *p1, *p2;  // 둘 다 포인터
   int *p1, p2;   // p2는 int 변수
------------------------------------------------------------
슬라이드 키워드
- 포인터 개념
- 변수의 주소(&)
- 간접참조(*)
------------------------------------------------------------
*/

int main(void)
{
    int i = 3000;
    int x = 10, y = 20;
    double f = 12.3;

    int *pi = NULL;
    double *pf = NULL;
    int *pnull = NULL;

    // 주소 출력: %p 사용 (컴파일러 경고를 피하려면 (void*) 캐스팅 권장)
    printf("&i = %p\n", (void *)&i);
    printf("&x = %p, &y = %p\n", (void *)&x, (void *)&y);
    printf("&f = %p\n\n", (void *)&f);

    // 포인터가 i를 가리키는 경우
    // pi에 i의 주소를 저장하고, *pi로 i의 값을 읽는다.
    pi = &i;
    printf("pi = %p\n", (void *)pi);
    printf("*pi = %d\n\n", *pi);

    // 같은 포인터가 다른 변수를 가리키는 경우
    // pi가 가리키는 대상이 바뀌면 *pi 값도 달라진다.
    pi = &x;
    printf("pi = %p, *pi = %d\n", (void *)pi, *pi);
    pi = &y;
    printf("pi = %p, *pi = %d\n\n", (void *)pi, *pi);

    // 다른 타입 포인터
    // double 포인터는 double 변수의 주소를 담는다.
    pf = &f;
    printf("pf = %p, *pf = %.1f\n", (void *)pf, *pf);

    // NULL 포인터는 아직 아무것도 가리키지 않는다는 의미
    // *pnull은 위험하므로 절대 역참조하지 않는다.
    if (pnull == NULL) {
        printf("pnull is NULL (do not dereference)\\n");
    }

    return 0;
}
