#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
[practice05] 센서 데이터 저장
------------------------------------------------------------
요구사항
1) 사용자 입력으로 센서 값 3개를 저장하는 함수를 작성하시오.
2) 100~200 사이 난수로 센서 값 3개를 저장하는 함수도 작성하시오.
3) 두 방식의 결과를 각각 출력하여 비교하시오.
------------------------------------------------------------
*/

void get_sensor_data_input(double *p)
{
    for (int i = 0; i < 3; i++) scanf("%lf", &p[i]);
}

void get_sensor_data_random(double *p)
{
    for (int i = 0; i < 3; i++) {
        p[i] = 100 + rand() % 101; // 100~200
    }
}

int main(void)
{
    double sensor_input[3] = {0};
    double sensor_random[3] = {0};

    printf("세 개의 센서 값을 입력하세요: ");
    get_sensor_data_input(sensor_input);
    printf("input sensor : %.1f %.1f %.1f\n",
           sensor_input[0], sensor_input[1], sensor_input[2]);

    srand((unsigned int)time(NULL));
    get_sensor_data_random(sensor_random);
    printf("random sensor: %.1f %.1f %.1f\n",
           sensor_random[0], sensor_random[1], sensor_random[2]);
    return 0;
}
