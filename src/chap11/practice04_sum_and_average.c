#include <stdio.h>

/*
[practice04] 합과 평균 함께 구하기
------------------------------------------------------------
요구사항
1) sum_and_average()를 완성하시오.
2) 합은 반환값으로, 평균은 avg 포인터를 통해 돌려주시오.
------------------------------------------------------------
*/

int sum_and_average(const int arr[], int n, double *avg)
{
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    *avg = (double)sum / n;
    return sum;
}

int main(void)
{
    int arr[5] = {90, 85, 100, 95, 80};
    double avg = 0.0;
    int sum = sum_and_average(arr, 5, &avg);

    printf("sum = %d\n", sum);
    printf("avg = %.2f\n", avg);
    return 0;
}
