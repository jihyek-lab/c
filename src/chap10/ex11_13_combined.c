#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 5

/*
[ex11~ex13 통합 예제: 2차원 배열 입력 방식의 다양성]
이 파일은 2차원 배열을 '하나의 배열'에 다양한 방식으로 입력/채우는 방법을 보여줍니다.
- 방식 1: 초기화 리스트로 직접 값 지정 (고정 데이터)
- 방식 2: 루프로 순차 값 채우기 (자동 증가)
- 방식 3: 루프로 랜덤 값 채우기 (무작위 데이터)

핵심: 2차원 배열은 [행][열] 구조로, 입력 방식에 따라 유연하게 사용할 수 있습니다.
*/

int main(void)
{
    int arr[ROWS][COLS];  // 하나의 2차원 배열로 다양한 입력 방식 시연
    int i, j;

    printf("=== 방식 1: 초기화 리스트로 직접 값 지정 (고정 데이터) ===\n");
    /*
    입력 방식: 선언 시 중괄호 {}로 값 나열.
    - 장점: 코드에 데이터가 명시적, 변경 쉽지 않음.
    - 용도: 테스트 데이터나 고정 테이블 (예: 학생 성적).
    - ex13에서 영감: 한 행 = 한 학생의 데이터.
    */
    int temp_scores[ROWS][COLS] = {
        {87, 98, 80, 76, 3},  // 학생1 데이터
        {99, 89, 90, 90, 0},  // 학생2
        {65, 68, 50, 49, 0}   // 학생3
    };
    // arr에 복사 (다양성 시연)
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = temp_scores[i][j];
        }
    }
    printf("배열 내용:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("=== 방식 2: 루프로 순차 값 채우기 (자동 증가) ===\n");
    /*
    입력 방식: 이중 for문으로 value++ 패턴 사용.
    - 장점: 코드로 값 생성, 패턴 예측 가능.
    - 용도: 테스트용 더미 데이터나 인덱스 기반 값 (ex11 스타일).
    - 다양성: 시작 값이나 증가 패턴 변경 가능.
    */
    int value = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = value++;  // 0부터 순차 증가
        }
    }
    printf("배열 내용 (0부터 순차):\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("=== 방식 3: 루프로 랜덤 값 채우기 (무작위 데이터) ===\n");
    /*
    입력 방식: rand() 함수로 무작위 값 채우기.
    - 장점: 매번 다른 데이터, 현실성 높음.
    - 용도: 시뮬레이션, 테스트 데이터 생성 (ex12 스타일).
    - 다양성: 범위(%100)나 시드 변경으로 조정 가능.
    */
    srand((unsigned int)time(NULL));  // 랜덤 시드 설정
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 100;  // 0~99 랜덤
        }
    }
    printf("배열 내용 (랜덤 0~99):\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%02d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}