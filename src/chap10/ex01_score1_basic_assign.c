#include <stdio.h>

/*
핵심 포인트
1) 배열 인덱스는 0부터 시작한다.
2) int scores[5]의 유효 인덱스는 0~4다.
3) 범위를 벗어난 접근은 미정의 동작이다.
*/
int main(void)
{
    int i;
    int scores[5];

    scores[0] = 10;
    scores[1] = 20;
    scores[2] = 30;
    scores[3] = 40;
    scores[4] = 50;

    for (i = 0; i < 5; i++) {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    return 0;
}
