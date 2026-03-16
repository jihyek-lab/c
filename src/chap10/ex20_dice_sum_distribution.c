#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
[과제] 주사위 합 분포
- 주사위 2개를 10,000번 던져 합(2~12)의 빈도를 계산한다.
- 합의 범위는 2~12이므로 크기 11의 배열을 사용한다.
- 결과를 표 형태로 출력한다.

[요구사항]
1) srand(time(NULL))로 난수 시드를 설정한다.
2) rand() % 6 + 1로 주사위 눈(1~6)을 만든다.
3) sum = d1 + d2 를 계산하고, freq[sum-2]를 증가한다.
4) 합 2~12와 빈도를 출력한다.
*/

int main(void)
{
    int freq[11] = {0}; // 2~12의 빈도 저장 (인덱스 0=2, 1=3, ..., 10=12)
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < 10000; i++) {
        int d1 = rand() % 6 + 1;
        int d2 = rand() % 6 + 1;
        int sum = d1 + d2;      // 2 ~ 12
        freq[sum - 2]++;        // 인덱스 0 ~ 10
    }

    printf("합  빈도\n");
    for (i = 0; i < 11; i++) {
        printf("%2d  %d\n", i + 2, freq[i]);
    }

    return 0;
}
