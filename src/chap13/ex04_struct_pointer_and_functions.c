#include <stdio.h>

/*
[ex04] 구조체 포인터와 함수
------------------------------------------------------------
핵심
1) 구조체 포인터는 -> 연산자로 멤버에 접근한다.
2) 구조체를 값으로 전달하면 복사본이 생성된다.
3) 포인터로 전달하면 원본을 수정할 수 있고 비용이 적다.
4) 읽기 전용이면 const struct* 를 사용한다.
------------------------------------------------------------
슬라이드 키워드
- 구조체 포인터/-> 연산자
- 구조체와 함수(값/포인터 전달)
- const 포인터 매개변수
------------------------------------------------------------
*/

struct student {
    int number;
    char name[20];
    double grade;
};

void print_student(const struct student *p)
{
    // const 포인터: 읽기 전용
    printf("%d %s %.2f\n", p->number, p->name, p->grade);
}

void raise_grade(struct student *p, double delta)
{
    // 포인터를 통해 원본 수정
    p->grade += delta;
}

struct vector {
    double x;
    double y;
};

struct vector get_vector_sum(struct vector a, struct vector b)
{
    struct vector r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r; // 구조체 반환(복사본)
}

int main(void)
{
    struct student s = {1, "Hong", 4.0};
    struct student *p = &s; // 구조체 포인터

    // -> 연산자 사용
    print_student(p);
    raise_grade(p, 0.3);
    print_student(p);

    // 구조체 반환 예시
    struct vector a = {2.0, 3.0};
    struct vector b = {5.0, 6.0};
    struct vector sum = get_vector_sum(a, b);
    printf("vector sum = (%.1f, %.1f)\n", sum.x, sum.y);

    return 0;
}
