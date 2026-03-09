#include <stdio.h>

#define YEARS 3
#define PRODUCTS 5

/*
핵심 포인트
1) 2차원 배열을 함수로 전달할 때 열 크기(PRODUCTS)는 고정되어야 한다.
2) 전체 합계는 이중 반복문 누적으로 계산한다.
3) 2차원 배열 파라미터 선언 형태를 익힌다.
*/
int sum(int sales[YEARS][PRODUCTS])
{
    int y;
    int p;
    int total = 0;

    for (y = 0; y < YEARS; y++) {
        for (p = 0; p < PRODUCTS; p++) {
            total += sales[y][p];
        }
    }

    return total;
}

int main(void)
{
    int sales[YEARS][PRODUCTS] = {
        {1, 2, 3, 4, 5},
        {4, 5, 6, 7, 8},
        {7, 8, 9, 10, 11}
    };

    printf("총 매출 합계 = %d\n", sum(sales));

    return 0;
}
