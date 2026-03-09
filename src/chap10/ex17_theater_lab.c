#include <stdio.h>

#define SIZE 10

/*
핵심 포인트
1) 좌석 상태(0/1)를 배열로 관리하면 예약 상태 추적이 쉽다.
2) 사용자 입력 검증(범위 체크)은 필수다.
3) 상태를 출력-입력-갱신 순서로 반복하는 패턴을 익힌다.
*/
int main(void)
{
    char ans1;
    int ans2;
    int i;
    int seats[SIZE] = {0};

    while (1) {
        printf("좌석을 예약하시겠습니까?(y 또는 n): ");
        scanf(" %c", &ans1);

        if (ans1 == 'y') {
            printf("-------------------------------\n");
            printf("  1  2  3  4  5  6  7  8  9 10\n");
            printf("-------------------------------\n");
            for (i = 0; i < SIZE; i++) {
                printf("  %d", seats[i]);
            }
            printf("\n예약할 좌석 번호 입력: ");
            scanf("%d", &ans2);

            if (ans2 <= 0 || ans2 > SIZE) {
                printf("1~10 사이 숫자를 입력하세요.\n");
                continue;
            }

            if (seats[ans2 - 1] == 0) {
                seats[ans2 - 1] = 1;
                printf("예약되었습니다.\n");
            } else {
                printf("이미 예약된 좌석입니다.\n");
            }
        } else if (ans1 == 'n') {
            break;
        }
    }

    return 0;
}
