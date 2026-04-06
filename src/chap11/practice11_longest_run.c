#include <stdio.h>

/*
[practice11] 가장 긴 연속 구간 길이
------------------------------------------------------------
요구사항
1) 같은 수가 연속으로 가장 길게 나온 길이를 구하시오.
2) 어떤 값이 그 길이를 만들었는지도 함께 출력하시오.
------------------------------------------------------------
*/

void find_longest_run(const int arr[], int n, int *bestValue, int *bestLen)
{
    int currentLen = 1;
    *bestLen = 1;
    *bestValue = arr[0];

    for (int i = 1; i < n; i++) {
        // 바로 앞 원소와 같으면 연속 구간이 이어진다.
        if (arr[i] == arr[i - 1]) {
            currentLen++;
        } else {
            // 값이 달라지면 연속 구간이 끊기므로 길이를 1로 다시 시작한다.
            currentLen = 1;
        }

        // 이번 연속 길이가 최고 기록보다 길면
        // 길이와 값을 함께 갱신한다.
        if (currentLen > *bestLen) {
            *bestLen = currentLen;
            *bestValue = arr[i];
        }
    }
}

int main(void)
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 3, 1};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int bestValue = 0;
    int bestLen = 0;

    find_longest_run(arr, n, &bestValue, &bestLen);

    printf("value = %d\n", bestValue);
    printf("longest run = %d\n", bestLen);
    return 0;
}
