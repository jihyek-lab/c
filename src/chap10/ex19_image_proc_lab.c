#include <stdio.h>

#define R 8
#define C 16

/*
핵심 포인트
1) 2차원 배열을 이미지(픽셀 격자)처럼 취급할 수 있다.
2) 0/1 반전(inverse)은 조건문으로 간단히 구현된다.
3) 영상 처리의 기본은 "모든 픽셀 순회 후 변환"이다.
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
    int image[R][C] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    printf("원본 이미지\n");
    display(image);

    inverse(image);

    printf("\n반전 이미지\n");
    display(image);

    return 0;
}
