#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

/*
핵심 포인트
1) 최소값 탐색은 "현재 최소값"을 기준으로 비교한다.
2) 초기 최소값은 보통 첫 원소로 둔다.
3) 배열 순회 중 조건이 맞으면 즉시 갱신한다.
*/
int main(void)
{
    int prices[SIZE] = {0};
    int i;
    int minimum;

    srand((unsigned int)time(NULL));

    for (i = 0; i < SIZE; i++) {
        prices[i] = (rand() % 100) + 1;
        printf("%3d ", prices[i]);
    }
    printf("\n");

    minimum = prices[0];
    for (i = 1; i < SIZE; i++) {
        if (prices[i] < minimum) {
            minimum = prices[i];
        }
    }

    printf("최소값 = %d\n", minimum);

    return 0;
}
