#include <stdio.h>

#define COUNT 5

/*
[practice14] 정렬 없이 순위 계산
------------------------------------------------------------
요구사항
1) 점수를 정렬하지 말고 각 학생의 등수를 계산하시오.
2) 자기보다 큰 점수 개수를 세어 등수를 구하시오.
------------------------------------------------------------
*/

void calculate_rank(const int scores[], int rank[], int n)
{
    for (int i = 0; i < n; i++) {
        // 기본 등수는 1등으로 시작한다.
        rank[i] = 1;

        // 자기보다 큰 점수가 하나 발견될 때마다 등수를 1씩 뒤로 민다.
        for (int j = 0; j < n; j++) {
            if (scores[j] > scores[i]) rank[i]++;
        }
    }
}

int main(void)
{
    int scores[COUNT] = {88, 95, 72, 90, 84};
    int rank[COUNT];

    calculate_rank(scores, rank, COUNT);

    for (int i = 0; i < COUNT; i++) {
        printf("score=%d, rank=%d\n", scores[i], rank[i]);
    }
    return 0;
}
