#include <stdio.h>

#define STUDENTS 5

/*
핵심 포인트
1) scanf("%d", &scores[i])로 배열 원소에 직접 입력한다.
2) 합계를 누적한 뒤 평균을 계산한다.
3) 정수/실수 평균 차이를 확인하려면 형변환을 사용한다.
*/
int main(void)
{
    int scores[STUDENTS];
    int sum = 0;
    int i;

    for (i = 0; i < STUDENTS; i++) {
        printf("학생 #%d 점수 입력: ", i + 1);
        scanf("%d", &scores[i]);
    }

    for (i = 0; i < STUDENTS; i++) {
        sum += scores[i];
    }

    printf("정수 평균 = %d\n", sum / STUDENTS);
    printf("실수 평균 = %.2f\n", (double)sum / STUDENTS);

    return 0;
}
