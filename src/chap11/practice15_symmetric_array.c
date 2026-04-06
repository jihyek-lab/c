#include <stdio.h>

/*
[practice15] 좌우 대칭 배열 검사
------------------------------------------------------------
요구사항
1) 배열이 앞뒤로 같은지 검사하시오.
2) 대칭이면 yes, 아니면 no를 출력하시오.
------------------------------------------------------------
*/

int is_symmetric_array(const int arr[], int n)
{
    // 양 끝에서 가운데로 오면서 값을 비교한다.
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            // 한 쌍이라도 다르면 대칭이 아니다.
            return 0;
        }
    }

    // 끝까지 문제가 없으면 대칭이다.
    return 1;
}

int main(void)
{
    int arr[] = {1, 2, 3, 2, 1};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));

    printf("symmetric = %s\n", is_symmetric_array(arr, n) ? "yes" : "no");
    return 0;
}
