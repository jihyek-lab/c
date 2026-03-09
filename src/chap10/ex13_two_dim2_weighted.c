#include <stdio.h>

#define ROWS 3
#define COLS 5

/*
핵심 포인트
1) 한 행을 "학생 1명의 성적 데이터"로 해석한다.
2) 열별 가중치를 적용해 최종 점수를 계산한다.
3) 2차원 배열은 테이블형 데이터 처리에 적합하다.
*/
int main(void)
{
    int a[ROWS][COLS] = {
        {87, 98, 80, 76, 3},
        {99, 89, 90, 90, 0},
        {65, 68, 50, 49, 0}
    };
    int i;

    for (i = 0; i < ROWS; i++) {
        double final_score = a[i][0] * 0.3 + a[i][1] * 0.4 +
                             a[i][2] * 0.2 + a[i][3] * 0.1 - a[i][4];
        printf("학생 #%d 최종점수 = %.2f\n", i + 1, final_score);
    }

    return 0;
}
