#include <stdio.h>

/*
[practice09] 최빈값 구하기
------------------------------------------------------------
요구사항
1) 배열에서 가장 많이 등장한 값을 찾으시오.
2) 등장 횟수도 함께 출력하시오.
3) 동점이면 먼저 나온 값을 유지하시오.
------------------------------------------------------------
*/

void find_mode(const int arr[], int n, int *mode, int *maxCount)
{
    *mode = arr[0];
    *maxCount = 0;

    // 바깥 반복문: "후보 값"을 하나씩 잡는다.
    for (int i = 0; i < n; i++) {
        int count = 0;

        // 안쪽 반복문: 후보 arr[i]가 배열 전체에 몇 번 나오는지 센다.
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) count++;
        }

        // 지금까지의 최다 등장 횟수보다 크면
        // 최빈값 후보와 횟수를 갱신한다.
        if (count > *maxCount) {
            *maxCount = count;
            *mode = arr[i];
        }
    }
}

int main(void)
{
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 2, 3, 5};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int mode = 0;
    int maxCount = 0;

    find_mode(arr, n, &mode, &maxCount);

    printf("mode = %d\n", mode);
    printf("count = %d\n", maxCount);
    return 0;
}
