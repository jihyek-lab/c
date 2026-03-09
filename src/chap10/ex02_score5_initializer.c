#include <stdio.h>

/*
핵심 포인트
1) 배열은 선언 시 중괄호로 초기화할 수 있다.
2) 초기값은 인덱스 순서대로 저장된다.
3) 고정 데이터 테스트에 유용하다.
*/
int main(void)
{
    int i;
    int scores[5] = {31, 63, 62, 87, 14};

    for (i = 0; i < 5; i++) {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    return 0;
}
