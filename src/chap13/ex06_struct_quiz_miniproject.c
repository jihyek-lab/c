#include <stdio.h>

/*
[ex06] 미니 프로젝트: 4지선다 퀴즈
------------------------------------------------------------
핵심
1) 문제/보기/정답을 구조체로 묶는다.
2) 여러 문제를 구조체 배열로 관리한다.
3) 사용자 입력과 정답 비교로 채점한다.
------------------------------------------------------------
슬라이드 키워드
- 구조체 배열
- 미니 프로젝트(퀴즈)
------------------------------------------------------------
*/

#define SIZE 100
#define QUIZ_COUNT 2

struct QUESTION {
    char question[SIZE];
    char item1[SIZE];
    char item2[SIZE];
    char item3[SIZE];
    char item4[SIZE];
    int solution;
};

int main(void)
{
    struct QUESTION bank[QUIZ_COUNT] = {
        {"임베디드 장치에 가장 적합한 언어는?", "1. Python", "2. Java", "3. C", "4. Javascript", 3},
        {"서로 다른 자료형을 모을 수 있는 구조는?", "1. 배열", "2. 변수", "3. 구조체", "4. 포인터", 3}
    };

    int score = 0;
    // 구조체 배열을 순회하며 문제 출력
    for (int i = 0; i < QUIZ_COUNT; i++) {
        int ans;
        printf("Q%d. %s\n", i + 1, bank[i].question);
        printf("%s\n%s\n%s\n%s\n", bank[i].item1, bank[i].item2, bank[i].item3, bank[i].item4);
        printf("정답 입력: ");
        scanf("%d", &ans);

        if (ans == bank[i].solution) {
            printf("정답!\n\n");
            score++;
        } else {
            printf("오답!\n\n");
        }
    }

    printf("점수: %d/%d\n", score, QUIZ_COUNT);
    return 0;
}
