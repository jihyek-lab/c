#include <stdio.h>

/*
[문제 설명]
3x3 틱택토 보드를 만들고, 번갈아 X와 O를 놓는 간단한 실습이다.
승패 판정은 하지 않고, 총 9번 입력하며 보드 상태를 출력한다.

[핵심 포인트]
1) 게임판은 2차원 char 배열로 표현한다.
2) 턴 수(k)를 이용해 X/O를 번갈아 배치한다.
3) 좌표 범위와 중복 선택을 검사한다.
4) 매 턴마다 보드를 출력해 상태 변화를 확인한다.
*/
int main(void)
{
    char board[3][3];
    int x;
    int y;
    int k;
    int i;

    // 보드 초기화 (빈 칸은 공백)
    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            board[x][y] = ' ';
        }
    }

    for (k = 0; k < 9; k++) {
        printf("(x, y) 좌표 입력(0~2): ");
        scanf("%d %d", &x, &y);

        // 범위 검사
        if (x < 0 || x > 2 || y < 0 || y > 2) {
            printf("좌표 범위 오류, 다시 입력하세요.\n");
            k--;
            continue;
        }
        // 중복 선택 검사
        if (board[x][y] != ' ') {
            printf("이미 선택된 칸입니다. 다시 입력하세요.\n");
            k--;
            continue;
        }

        // 턴 수에 따라 X/O 번갈아 배치
        board[x][y] = (k % 2 == 0) ? 'X' : 'O';

        // 현재 보드 출력
        for (i = 0; i < 3; i++) {
            printf("---|---|---\n");
            printf("%c  | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        }
        printf("---|---|---\n");
    }

    return 0;
}
