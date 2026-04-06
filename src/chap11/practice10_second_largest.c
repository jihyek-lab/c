#include <stdio.h>
#include <limits.h>

/*
[practice10] 두 번째로 큰 값 찾기
------------------------------------------------------------
요구사항
1) 배열에서 가장 큰 값과 두 번째로 큰 값을 구하시오.
2) 중복된 최댓값은 하나로 취급하시오.
------------------------------------------------------------
*/

void find_two_largest(const int arr[], int n, int *first, int *second)
{
    *first = INT_MIN;
    *second = INT_MIN;

    for (int i = 0; i < n; i++) {
        // 현재 값이 가장 큰 값보다 크면,
        // 기존 first를 second로 내리고 현재 값을 first로 올린다.
        if (arr[i] > *first) {
            *second = *first;
            *first = arr[i];
        // first보다는 작지만 second보다는 크면
        // 두 번째 큰 값 후보를 갱신한다.
        } else if (arr[i] > *second && arr[i] < *first) {
            *second = arr[i];
        }
    }
}

int main(void)
{
    int arr[] = {40, 90, 15, 90, 72, 88, 63};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int first = 0;
    int second = 0;

    find_two_largest(arr, n, &first, &second);

    printf("largest = %d\n", first);
    printf("second largest = %d\n", second);
    return 0;
}
