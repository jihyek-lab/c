#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 8
#define C 16

/*
[프로그램 설명]
0과 1로 구성된 2차원 배열을 랜덤으로 초기화하고,
원본/반전 이미지를 출력하는 버전이다.

[핵심 포인트]
1) srand(time(NULL))로 난수 시드를 설정한다.
2) rand() % 2로 0 또는 1을 생성한다.
3) display()로 0/1 값을 화면 기호(*, _)로 출력한다.
4) inverse()로 모든 픽셀을 0<->1 반전한다.
*/
void display(int image[R][C])
{
    int r;
    int c;

    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            if (image[r][c] == 0) {
                printf("*");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }
}

void inverse(int img[R][C])
{
    int r;
    int c;

    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            if (img[r][c] == 0) {
                img[r][c] = 1;
            } else {
                img[r][c] = 0;
            }
        }
    }
}

int main(void)
{
    int image[R][C];
    int r;
    int c;

    srand((unsigned int)time(NULL));

    // 랜덤 이미지 생성 (0 또는 1)
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            image[r][c] = rand() % 2;
        }
    }

    printf("원본 이미지\n");
    display(image);

    inverse(image);

    printf("\n반전 이미지\n");
    display(image);

    return 0;
}
