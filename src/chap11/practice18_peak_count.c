#include <stdio.h>

/*
[practice18] 봉우리 개수 세기
------------------------------------------------------------
요구사항
1) 양옆 값보다 큰 원소를 봉우리(peak)라고 하시오.
2) 봉우리의 개수를 구하시오.
3) 첫 번째 봉우리의 위치도 함께 출력하시오.
------------------------------------------------------------
*/

void count_peaks(const int arr[], int n, int *peakCount, int *firstPeakIndex)
{
    *peakCount = 0;
    *firstPeakIndex = -1;

    // 양끝 원소는 양옆 비교가 불가능하므로 가운데 구간만 검사한다.
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            (*peakCount)++;

            // 가장 먼저 발견한 봉우리 위치를 기억한다.
            if (*firstPeakIndex == -1) {
                *firstPeakIndex = i;
            }
        }
    }
}

int main(void)
{
    int arr[] = {1, 3, 2, 5, 4, 6, 2};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    int peakCount = 0;
    int firstPeakIndex = -1;

    count_peaks(arr, n, &peakCount, &firstPeakIndex);

    printf("peak count = %d\n", peakCount);
    printf("first peak index = %d\n", firstPeakIndex);
    return 0;
}
