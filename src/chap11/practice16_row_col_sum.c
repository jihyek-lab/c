#include <stdio.h>

#define ROWS 3
#define COLS 4

/*
[practice16] 2차원 배열의 행/열 합 비교
------------------------------------------------------------
요구사항
1) 각 행의 합을 구하시오.
2) 각 열의 합을 구하시오.
3) 가장 합이 큰 행 번호와 열 번호를 찾으시오.
------------------------------------------------------------
*/

void print_row_sums(const int arr[ROWS][COLS], int *bestRow)
{
    int bestRowSum = -1;
    *bestRow = 0;

    for (int r = 0; r < ROWS; r++) {
        int sum = 0;

        // 한 행의 모든 열을 더해 row sum을 만든다.
        for (int c = 0; c < COLS; c++) sum += arr[r][c];
        printf("row %d sum = %d\n", r, sum);

        // 지금 행의 합이 가장 크면 행 번호를 기억해 둔다.
        if (sum > bestRowSum) {
            bestRowSum = sum;
            *bestRow = r;
        }
    }
}

void print_col_sums(const int arr[ROWS][COLS], int *bestCol)
{
    int bestColSum = -1;
    *bestCol = 0;

    for (int c = 0; c < COLS; c++) {
        int sum = 0;

        // 한 열의 모든 행을 더해 col sum을 만든다.
        for (int r = 0; r < ROWS; r++) sum += arr[r][c];
        printf("col %d sum = %d\n", c, sum);

        // 지금 열의 합이 가장 크면 열 번호를 기억해 둔다.
        if (sum > bestColSum) {
            bestColSum = sum;
            *bestCol = c;
        }
    }
}

int main(void)
{
    int arr[ROWS][COLS] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {50, 20, 10, 5}
    };
    int bestRow = 0, bestCol = 0;

    print_row_sums(arr, &bestRow);
    print_col_sums(arr, &bestCol);

    printf("best row = %d\n", bestRow);
    printf("best col = %d\n", bestCol);
    return 0;
}
