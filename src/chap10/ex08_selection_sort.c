#include <stdio.h>

#define SIZE 10

/*
핵심 포인트
1) 선택 정렬은 매 단계에서 최소 원소 위치를 찾는다.
2) 찾은 최소 원소를 현재 시작 위치와 교환한다.
3) 시간복잡도 O(n^2), 구현이 단순해 학습용으로 적합하다.
*/
int main(void)
{
    int list[SIZE] = {3, 2, 9, 7, 1, 4, 8, 0, 6, 5};
    int i;
    int j;
    int temp;
    int least;

    for (i = 0; i < SIZE - 1; i++) {
        least = i;

        for (j = i + 1; j < SIZE; j++) {
            if (list[j] < list[least]) {
                least = j;
            }
        }

        temp = list[i];
        list[i] = list[least];
        list[least] = temp;
    }

    for (i = 0; i < SIZE; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
