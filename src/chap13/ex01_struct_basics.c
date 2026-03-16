#include <stdio.h>
#include <string.h>

/*
[ex01] 구조체 기본: 정의, 변수 선언, 멤버 접근
------------------------------------------------------------
핵심
1) struct는 서로 다른 타입을 묶는 사용자 정의 자료형이다.
2) 구조체 정의와 변수 선언은 다른 개념이다.
3) 멤버 접근은 점(.) 연산자를 사용한다.
슬라이드 키워드
- 구조체 정의/변수 선언
- 멤버 접근(.)
------------------------------------------------------------
*/

struct student {
    int number;
    char name[10];
    double grade;
};

int main(void)
{
    struct student s; // 구조체 변수 선언

    // 점(.) 연산자로 멤버 접근
    s.number = 20230001;
    strcpy(s.name, "홍길동");
    s.grade = 4.3;

    printf("학번: %d\n", s.number);
    printf("이름: %s\n", s.name);
    printf("학점: %.2f\n", s.grade);

    // 구조체 멤버는 주소로도 입력 가능
    // scanf에서 구조체 멤버의 주소 전달
    printf("\n학번을 입력하시오: ");
    scanf("%d", &s.number);
    printf("이름을 입력하시오: ");
    scanf("%9s", s.name);
    printf("학점을 입력하시오(실수): ");
    scanf("%lf", &s.grade);

    printf("\n학번: %d\n", s.number);
    printf("이름: %s\n", s.name);
    printf("학점: %.2f\n", s.grade);

    return 0;
}
