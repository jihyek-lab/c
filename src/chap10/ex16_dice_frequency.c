#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

/*
[설명]
주사위를 10,000번 던졌다고 가정하고, 각 면(1~6)의 출현 횟수를 세는 프로그램이다.
핵심은 "값 -> 인덱스"로 매핑해서 빈도를 배열에 누적하는 것.

[핵심 흐름]
1) freq[6] 배열을 0으로 초기화한다. (각 면의 빈도 저장)
2) rand() % 6으로 0~5 값을 뽑고, 해당 칸을 ++로 증가한다.
3) 출력할 때는 인덱스 i를 주사위 면 i+1로 바꿔서 보여준다.

[왜 이렇게 매핑하나]
- 주사위 면은 1~6인데 배열은 0부터 시작한다.
- 그래서 "면 번호 - 1"을 인덱스로 삼으면 깔끔하게 카운팅 가능하다.
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
