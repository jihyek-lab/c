#include <stdio.h>
#include <string.h>

/*
[ex03] 구조체 배열
------------------------------------------------------------
핵심
1) 구조체도 배열로 관리할 수 있다.
2) 배열 크기 계산은 sizeof를 사용한다.
3) 구조체 배열 요소의 멤버는 list[i].member로 접근한다.
------------------------------------------------------------
슬라이드 키워드
- 구조체 배열
- sizeof로 요소 개수 계산
------------------------------------------------------------
*/

struct student {
    int number;
    char name[20];
    double grade;
};

int main(void)
{
    struct student list[3] = {
        {1, "Park", 3.42},
        {2, "Kim", 4.31},
        {3, "Lee", 2.98}
    };

    // 구조체 배열 개수 계산
    int n = (int)(sizeof(list) / sizeof(list[0]));
    for (int i = 0; i < n; i++) {
        printf("%d %s %.2f\n", list[i].number, list[i].name, list[i].grade);
    }

    // 요소 수정 예시
    list[1].grade = 4.50;
    strcpy(list[1].name, "KIM");

    printf("\nupdated:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %.2f\n", list[i].number, list[i].name, list[i].grade);
    }

    return 0;
}
