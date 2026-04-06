#include <stdio.h>

/*
[practice01] 배열의 첫/마지막 원소 교환 후 전체 합 구하기
------------------------------------------------------------
요구사항
1) swap_by_address()를 완성하시오.
2) sum_array()를 완성하시오.
3) main()의 출력으로 교환 전/후 배열과 전체 합을 확인하시오.
------------------------------------------------------------
*/

void print_array(const int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap_by_address(int *px, int *py)
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

int sum_array(const int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};

    printf("before: ");
    print_array(arr, 5);

    swap_by_address(&arr[0], &arr[4]);

    printf("after : ");
    print_array(arr, 5);

    printf("sum   : %d\n", sum_array(arr, 5));
    return 0;
}
