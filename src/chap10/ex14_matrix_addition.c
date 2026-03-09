#include <stdio.h>

#define ROWS 3
#define COLS 3

/*
핵심 포인트
1) 행렬 덧셈은 같은 위치 원소끼리 더한다.
2) C[r][c] = A[r][c] + B[r][c] 패턴을 반복한다.
3) 수치 계산/영상 처리 기초 연산으로 자주 등장한다.
*/
int main(void)
{
    int a[ROWS][COLS] = {
        {2, 3, 0},
        {8, 9, 1},
        {7, 0, 5}
    };
    int b[ROWS][COLS] = {
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0}
    };
    int c[ROWS][COLS];
    int r;
    int col;

    for (r = 0; r < ROWS; r++) {
        for (col = 0; col < COLS; col++) {
            c[r][col] = a[r][col] + b[r][col];
        }
    }

    for (r = 0; r < ROWS; r++) {
        for (col = 0; col < COLS; col++) {
            printf("%d ", c[r][col]);
        }
        printf("\n");
    }

    return 0;
}
