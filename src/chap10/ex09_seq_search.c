#include <stdio.h>

#define SIZE 10

/*
핵심 포인트
1) 순차 탐색은 앞에서부터 키를 비교한다.
2) 정렬되지 않은 배열에서도 사용 가능하다.
3) 최악의 경우 끝까지 비교하므로 O(n)이다.
*/
int main(void)
{
    int key;
    int i;
    int found = -1;
    int list[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("찾을 값 입력: ");
    scanf("%d", &key);

    for (i = 0; i < SIZE; i++) {
        if (list[i] == key) {
            found = i;
            break;
        }
    }

    if (found >= 0) {
        printf("찾은 인덱스 = %d\n", found);
    } else {
        printf("값을 찾지 못했습니다.\n");
    }

    return 0;
}
