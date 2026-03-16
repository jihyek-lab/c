#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
[과제] 가장 긴 연속 구간
- 길이 N의 0/1 배열을 만들고, 1이 가장 길게 연속된 구간 길이를 구한다.

[요구사항]
1) N=30 정도로 고정해도 되고, 상수로 정의해도 된다.
2) rand() % 2로 0/1을 생성하여 배열을 초기화한다.
3) 배열을 한 번 순회하며 최장 연속 1의 길이를 계산한다.
4) 배열과 최장 길이를 출력한다.
*/

#define N 30

int main(void)
{
    int a[N];
    int i;
    int current = 0;
    int max = 0;

    srand((unsigned int)time(NULL));

    for (i = 0; i < N; i++) {
        a[i] = rand() % 2;
    }

    printf("array: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0; i < N; i++) {
        if (a[i] == 1) {
            current++;
            if (current > max) max = current;
        } else {
            current = 0;
        }
    }

    printf("longest run of 1s = %d\n", max);
    return 0;
}
