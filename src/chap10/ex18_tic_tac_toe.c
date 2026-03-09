#include <stdio.h>

/*
핵심 포인트
1) 게임판은 2차원 char 배열로 표현 가능하다.
2) 턴 수(k)로 플레이어(X/O)를 번갈아 배치한다.
3) 좌표 입력 전 범위 검증이 필요하다.
*/
int main(void)
{
    char board[3][3];
    int x;
    int y;
    int k;
    int i;

    for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
            board[x][y] = ' ';
        }
    }

    for (k = 0; k < 9; k++) {
        printf("(x, y) 좌표 입력(0~2): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x > 2 || y < 0 || y > 2) {
            printf("좌표 범위 오류, 다시 입력하세요.\n");
            k--;
            continue;
        }
        if (board[x][y] != ' ') {
            printf("이미 선택된 칸입니다. 다시 입력하세요.\n");
            k--;
            continue;
        }

        board[x][y] = (k % 2 == 0) ? 'X' : 'O';

        for (i = 0; i < 3; i++) {
            printf("---|---|---\n");
            printf("%c  | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        }
        printf("---|---|---\n");
    }

    return 0;
}
