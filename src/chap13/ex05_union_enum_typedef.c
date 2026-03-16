#include <stdio.h>
#include <string.h>

/*
[ex05] 공용체, 열거형, typedef
------------------------------------------------------------
파트 A) 공용체(union)
- 같은 메모리 공간을 여러 타입이 공유한다.

파트 B) 태그 포함 공용체
- type 필드로 어떤 멤버가 유효한지 표시한다.

파트 C) enum과 typedef
- enum은 상수 집합, typedef는 타입 별칭이다.
------------------------------------------------------------
슬라이드 키워드
- 공용체(union)
- 태그 포함 공용체
- 열거형(enum)
- typedef
------------------------------------------------------------
*/

union example {
    int i;
    char c;
};

#define STU_NUMBER 1
#define REG_NUMBER 2

struct student_id {
    int type;
    union {
        int stu_number;
        char reg_number[15];
    } id;
    char name[20];
};

void print_id(struct student_id s)
{
    if (s.type == STU_NUMBER) {
        printf("학번: %d\n", s.id.stu_number);
    } else if (s.type == REG_NUMBER) {
        printf("주민등록번호: %s\n", s.id.reg_number);
    } else {
        printf("타입 오류\n");
    }
    printf("이름: %s\n", s.name);
}

enum tvtype { LCD, OLED };

typedef struct point {
    int x;
    int y;
} POINT;

int main(void)
{
    // (A) 공용체 예제: 같은 메모리를 서로 다른 타입이 공유
    union example v;
    v.c = 'A';
    printf("v.c=%c v.i=%d\n", v.c, v.i);
    v.i = 10000;
    printf("v.c=%c v.i=%d\n\n", v.c, v.i);

    // (B) 태그 포함 공용체: type 필드로 어떤 멤버가 유효한지 결정
    struct student_id s1;
    s1.type = STU_NUMBER;
    s1.id.stu_number = 20190001;
    strcpy(s1.name, "홍길동");
    print_id(s1);

    struct student_id s2;
    s2.type = REG_NUMBER;
    strcpy(s2.id.reg_number, "860101-1056076");
    strcpy(s2.name, "김철수");
    print_id(s2);

    // (C) enum, typedef: 의미 있는 이름으로 상수/타입을 정의
    enum tvtype code = LCD;
    if (code == LCD) printf("LCD TV\n");
    else printf("OLED TV\n");

    POINT p = {2, 3};
    printf("POINT p = (%d, %d)\n", p.x, p.y);

    return 0;
}
