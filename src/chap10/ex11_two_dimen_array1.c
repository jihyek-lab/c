#include <stdio.h>

#define ROWS 3
#define COLS 5

/*
핵심 포인트
1) 2차원 배열은 [행][열] 인덱스로 접근한다.
2) 이중 반복문으로 전체 요소를 채운다.
3) value++ 패턴으로 순차 값 채우기를 연습한다.
*/
int main(void)
{
    int s[ROWS][COLS];
    int i;
    int j;
    int value = 0;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            s[i][j] = value++;
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%2d ", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}
