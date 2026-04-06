#include <stdio.h>

/*
[practice06] 배열 오른쪽 한 칸 회전
------------------------------------------------------------
요구사항
1) rotate_right()를 완성하시오.
2) 예: {10, 20, 30, 40} -> {40, 10, 20, 30}
------------------------------------------------------------
*/

void print_array(const int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rotate_right(int arr[], int n)
{
    int last = arr[n - 1];

    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main(void)
{
    int arr[6] = {10, 20, 30, 40, 50, 60};

    printf("before: ");
    print_array(arr, 6);

    rotate_right(arr, 6);

    printf("after : ");
    print_array(arr, 6);
    return 0;
}
