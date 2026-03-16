#include <stdio.h>

#define SIZE 5

/*
[ex05] 2차원 배열과 포인터 순회
------------------------------------------------------------
핵심
1) 2차원 배열은 메모리에 연속적으로 배치된다.
2) &image[0][0]을 int*로 두고 1차원처럼 순회할 수 있다.
3) 모든 픽셀을 순회하며 값을 변경하는 패턴을 익힌다.
------------------------------------------------------------
슬라이드 키워드
- 2차원 배열
- 포인터 순회
- 영상 처리 예제
------------------------------------------------------------
*/

void print_image(int image[][SIZE])
{
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            printf("%03d ", image[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void brighten_image(int image[][SIZE])
{
    // 2차원 배열의 첫 원소 주소를 int*로 받아 1차원처럼 순회
    // SIZE*SIZE는 전체 원소 개수(연속 메모리)이다.
    int *p = &image[0][0];
    for (int i = 0; i < SIZE * SIZE; i++) {
        *p += 10;
        p++;
    }
}

int main(void)
{
    int image[SIZE][SIZE] = {
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50},
        {10, 20, 30, 40, 50}
    };

    // 원본 출력 -> 밝기 증가 -> 결과 출력
    print_image(image);
    brighten_image(image);
    print_image(image);

    return 0;
}
