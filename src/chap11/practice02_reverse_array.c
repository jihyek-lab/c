#include <stdio.h>

/*
[practice02] 배열 뒤집기
------------------------------------------------------------
요구사항
1) reverse_array()를 완성하시오.
2) 함수 호출 전/후 배열이 어떻게 달라지는지 확인하시오.
------------------------------------------------------------
*/

void print_array(const int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse_array(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }
}

int main(void)
{
    int arr[6] = {10, 20, 30, 40, 50, 60};

    printf("before: ");
    print_array(arr, 6);

    reverse_array(arr, 6);

    printf("after : ");
    print_array(arr, 6);
    return 0;
}
