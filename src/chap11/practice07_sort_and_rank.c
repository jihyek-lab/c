#include <stdio.h>
#include <string.h>

#define COUNT 5
#define NAME_LEN 20

/*
[practice07] 정렬 응용: 점수 순위표 만들기
------------------------------------------------------------
요구사항
1) 학생 이름 배열과 점수 배열을 함께 내림차순 정렬하시오.
2) 점수만 바꾸지 말고, 이름도 같이 이동해야 한다.
3) 정렬 후 순위표를 출력하시오.

학습 포인트
- 선택 정렬(selection sort) 응용
- 관련 있는 두 배열을 함께 교환하는 패턴
- 정렬 결과를 "순위표" 형태로 활용하기
------------------------------------------------------------
*/

void print_ranking(const char names[][NAME_LEN], const int scores[], int n)
{
    printf("=== ranking ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d위: %-10s %d\n", i + 1, names[i], scores[i]);
    }
}

void swap_score_and_name(int *a, int *b, char nameA[], char nameB[])
{
    int tempScore = *a;
    char tempName[NAME_LEN];

    *a = *b;
    *b = tempScore;

    strcpy(tempName, nameA);
    strcpy(nameA, nameB);
    strcpy(nameB, tempName);
}

void sort_by_score_desc(char names[][NAME_LEN], int scores[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (scores[j] > scores[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            swap_score_and_name(&scores[i], &scores[maxIndex], names[i], names[maxIndex]);
        }
    }
}

int main(void)
{
    char names[COUNT][NAME_LEN] = {"Kim", "Lee", "Park", "Choi", "Han"};
    int scores[COUNT] = {88, 95, 72, 90, 84};

    printf("before sort\n");
    print_ranking(names, scores, COUNT);

    sort_by_score_desc(names, scores, COUNT);

    printf("\nafter sort\n");
    print_ranking(names, scores, COUNT);

    return 0;
}
