#include <stdio.h>

#define SIZE 16

/*
핵심 포인트
1) 이진 탐색 전제: 배열이 오름차순 정렬되어 있어야 한다.
2) low/high/middle 인덱스로 탐색 구간을 절반씩 줄인다.
3) 성공 시 인덱스, 실패 시 -1을 반환하는 패턴을 익힌다.
*/
int binary_search(int list[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int middle = (low + high) / 2;

        if (key == list[middle]) {
            return middle;
        } else if (key > list[middle]) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    return -1;
}

int main(void)
{
    int key;
    int grade[SIZE] = {2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47};

    printf("찾을 값 입력: ");
    scanf("%d", &key);
    printf("탐색 결과 = %d\n", binary_search(grade, SIZE, key));

    return 0;
}
