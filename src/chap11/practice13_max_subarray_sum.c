#include <stdio.h>

/*
[practice13] 연속 부분 배열의 최대 합
------------------------------------------------------------
요구사항
1) 연속된 부분 배열 중 합이 가장 큰 값을 구하시오.
2) 이해를 위해 완전탐색 방식으로 구현하시오.
------------------------------------------------------------
*/

int max_subarray_sum(const int arr[], int n)
{
    int maxSum = arr[0];

    // start: 부분 배열의 시작 위치를 고른다.
    for (int start = 0; start < n; start++) {
        int sum = 0;
        // end: 같은 시작점에서 끝 위치를 한 칸씩 늘려 간다.
        for (int end = start; end < n; end++) {
            sum += arr[end];
            // start ~ end 구간의 합이 현재 최대보다 크면 갱신한다.
            if (sum > maxSum) maxSum = sum;
        }
    }

    return maxSum;
}

int main(void)
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("max subarray sum = %d\n", max_subarray_sum(arr, n));
    return 0;
}
