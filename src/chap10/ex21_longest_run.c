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

    // 난수 시드 설정 (실행마다 다른 배열 생성)
    srand((unsigned int)time(NULL));

    // 1) 0/1 배열 생성
    for (i = 0; i < N; i++) {
        a[i] = rand() % 2;
    }

    // 2) 생성된 배열 출력
    printf("array: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // 3) 배열 한 번 순회하며 최장 연속 1 길이 계산
    // current: 현재 연속된 1의 길이
    // max: 지금까지 발견된 최대 연속 길이
    for (i = 0; i < N; i++) {
        if (a[i] == 1) {
            current++;
            if (current > max) max = current;
        } else {
            current = 0;
        }
    }

    // 4) 결과 출력
    printf("longest run of 1s = %d\n", max);
    return 0;
}
