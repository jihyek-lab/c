#include <stdio.h>

/*
[practice12] 배열을 오른쪽으로 k칸 회전
------------------------------------------------------------
요구사항
1) 배열을 오른쪽으로 k칸 회전시키시오.
2) 보조 배열을 사용해도 된다.
------------------------------------------------------------
*/

void print_array(const int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rotate_right_k(int arr[], int n, int k)
{
    int temp[100];

    // k가 배열 길이보다 커도 같은 회전이 반복되므로 나머지만 쓰면 된다.
    k %= n;

    // arr[i]를 회전 후의 위치 (i + k) % n 로 보낸다.
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    // 보조 배열의 결과를 다시 원본 배열로 복사한다.
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int k = 2;

    printf("before: ");
    print_array(arr, n);

    rotate_right_k(arr, n, k);

    printf("after : ");
    print_array(arr, n);
    return 0;
}
