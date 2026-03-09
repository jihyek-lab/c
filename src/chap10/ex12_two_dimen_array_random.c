#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 5

/*
핵심 포인트
1) 2차원 배열도 1차원과 동일하게 rand()로 채울 수 있다.
2) 출력은 행 단위 줄바꿈으로 표처럼 보여준다.
3) 데이터가 행/열 구조를 가지면 2차원 배열이 직관적이다.
*/
int main(void)
{
    int s[ROWS][COLS];
    int i;
    int j;

    srand((unsigned int)time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            s[i][j] = rand() % 100;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%02d ", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}
