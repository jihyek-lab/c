#include <stdio.h>

#define R 8
#define C 16

/*
[프로그램 설명]
0과 1로 구성된 2차원 배열을 흑백 이미지로 보고,
모든 픽셀을 반전(0↔1)한 뒤 출력하는 간단한 영상 처리 예제다.

[핵심 포인트]
1) 2차원 배열을 이미지(픽셀 격자)처럼 취급할 수 있다.
2) display()는 0/1 값을 화면 기호(*, _)로 변환해 출력한다.
3) inverse()는 모든 픽셀을 순회하며 0과 1을 서로 바꾼다.
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
