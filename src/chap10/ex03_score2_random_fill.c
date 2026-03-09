#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

/*
핵심 포인트
1) srand(time(NULL))로 난수 시드를 초기화한다.
2) rand() % 100은 0~99 범위 정수를 만든다.
3) 배열 반복 초기화 패턴을 익힌다.
*/
int main(void)
{
    int i;
    int scores[SIZE];

    srand((unsigned int)time(NULL));

    for (i = 0; i < SIZE; i++) {
        scores[i] = rand() % 100;
    }

    for (i = 0; i < SIZE; i++) {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    return 0;
}
