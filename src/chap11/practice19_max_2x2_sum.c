#include <stdio.h>

#define ROWS 4
#define COLS 4

/*
[practice19] 2x2 부분 배열의 최대 합
------------------------------------------------------------
요구사항
1) 2차원 배열에서 모든 2x2 구간의 합을 구하시오.
2) 그중 합이 가장 큰 2x2 구간의 시작 위치를 찾으시오.
3) 최대 합도 함께 출력하시오.
------------------------------------------------------------
*/

void find_max_2x2_sum(const int arr[ROWS][COLS], int *bestRow, int *bestCol, int *bestSum)
{
    *bestRow = 0;
    *bestCol = 0;
    *bestSum = arr[0][0] + arr[0][1] + arr[1][0] + arr[1][1];

    for (int r = 0; r < ROWS - 1; r++) {
        for (int c = 0; c < COLS - 1; c++) {
            int sum = 0;

            // (r, c)를 왼쪽 위로 하는 2x2 구간의 합을 만든다.
            for (int i = r; i < r + 2; i++) {
                for (int j = c; j < c + 2; j++) {
                    sum += arr[i][j];
                }
            }

            // 지금 2x2 합이 가장 크면 위치와 합을 갱신한다.
            if (sum > *bestSum) {
                *bestSum = sum;
                *bestRow = r;
                *bestCol = c;
            }
        }
    }
}

int main(void)
{
    int arr[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {2, 9, 1, 3},
        {4, 5, 2, 6}
    };
    int bestRow = 0;
    int bestCol = 0;
    int bestSum = 0;

    find_max_2x2_sum(arr, &bestRow, &bestCol, &bestSum);

    printf("best 2x2 start = (%d, %d)\n", bestRow, bestCol);
    printf("max 2x2 sum = %d\n", bestSum);
    return 0;
}
