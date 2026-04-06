#include <stdio.h>

/*
[practice03] 최솟값과 최댓값 찾기
------------------------------------------------------------
요구사항
1) find_min_max()를 완성하시오.
2) 최소값과 최대값을 출력 매개변수로 돌려주시오.
------------------------------------------------------------
*/

void find_min_max(const int arr[], int n, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int main(void)
{
    int arr[7] = {35, 12, 77, 4, 29, 88, 16};
    int min_value = 0;
    int max_value = 0;

    find_min_max(arr, 7, &min_value, &max_value);

    printf("min = %d\n", min_value);
    printf("max = %d\n", max_value);
    return 0;
}
