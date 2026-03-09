#include <stdio.h>

#define STUDENTS 5

/*
핵심 포인트
1) 배열은 함수 인자로 전달 가능하다.
2) 함수는 배열 길이(size)를 함께 받는 습관이 중요하다.
3) 평균 계산 로직을 재사용 가능한 함수로 분리한다.
*/
int get_average(int scores[], int size)
{
    int i;
    int sum = 0;

    for (i = 0; i < size; i++) {
        sum += scores[i];
    }

    return sum / size;
}

int main(void)
{
    int scores[STUDENTS] = {90, 80, 70, 100, 95};
    int avg;

    avg = get_average(scores, STUDENTS);
    printf("평균 = %d\n", avg);

    return 0;
}
