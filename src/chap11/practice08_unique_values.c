#include <stdio.h>

/*
[practice08] 중복 제거 후 한 번만 출력
------------------------------------------------------------
요구사항
1) 배열을 앞에서부터 보며 처음 등장한 값만 출력하시오.
2) 이미 앞에서 나온 값이면 다시 출력하지 마시오.
------------------------------------------------------------
*/

void print_unique_values(const int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int duplicated = 0;

        // 현재 값 arr[i]가 "처음 나온 값인지" 확인한다.
        // 앞쪽 구간 0 ~ i-1만 검사하면 된다.
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                // 앞에서 같은 값을 이미 봤다면 중복이다.
                duplicated = 1;
                break;
            }
        }

        // 앞에서 한 번도 나오지 않은 값만 출력한다.
        if (!duplicated) {
            printf("%d ", arr[i]);
        }
    }
}

int main(void)
{
    int arr[] = {3, 1, 3, 2, 1, 5, 2, 4};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("unique values: ");
    print_unique_values(arr, n);
    printf("\n");
    return 0;
}
