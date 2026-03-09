#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

/*
핵심 포인트
1) 도수분포는 "값 -> 빈도"를 배열 인덱스로 매핑해서 센다.
2) 주사위 1~6을 인덱스 0~5로 관리한다.
3) ++freq[index] 패턴은 카운팅 문제의 기본이다.
*/
int main(void)
{
    int freq[SIZE] = {0};
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < 10000; i++) {
        ++freq[rand() % 6];
    }

    printf("면  빈도\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d   %d\n", i + 1, freq[i]);
    }

    return 0;
}
