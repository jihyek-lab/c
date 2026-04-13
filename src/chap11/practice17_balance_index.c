#include <stdio.h>

/*
[practice17] 균형 인덱스 찾기
------------------------------------------------------------
요구사항
1) 어떤 위치를 기준으로 왼쪽 합과 오른쪽 합이 같은 인덱스를 찾으시오.
2) 그런 위치가 여러 개면 가장 먼저 나오는 인덱스를 출력하시오.
3) 없으면 -1을 출력하시오.
------------------------------------------------------------
*/

int find_balance_index(const int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int leftSum = 0;
        int rightSum = 0;

        // i보다 왼쪽에 있는 값들의 합을 구한다.
        for (int j = 0; j < i; j++) leftSum += arr[j];

        // i보다 오른쪽에 있는 값들의 합을 구한다.
        for (int j = i + 1; j < n; j++) rightSum += arr[j];

        // 양쪽 합이 같아지는 첫 위치를 바로 반환한다.
        if (leftSum == rightSum) {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    int arr[] = {1, 7, 3, 6, 5, 6};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("balance index = %d\n", find_balance_index(arr, n));
    return 0;
}
