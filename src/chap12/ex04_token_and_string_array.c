#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
[ex04] 토큰 분리 + 문자열 배열
------------------------------------------------------------
파트 A) strtok로 토큰 분리
- 공백/구분자 기준으로 문자열을 나눈다.

파트 B) 문자열 배열
- 2차원 char 배열로 여러 문자열을 저장한다.
------------------------------------------------------------
슬라이드 키워드
- 문자열 토큰 분리(strtok)
- 문자열 배열
- 문자 포인터 배열
------------------------------------------------------------
*/

int main(void)
{
    // (A) strtok
    // strtok은 원본 문자열을 직접 잘라내므로 s는 수정된다.
    char s[] = "Man is immortal, because he has a soul";
    char seps[] = " ,\t\n";
    char *token = strtok(s, seps);

    while (token != NULL) {
        printf("token: %s\n", token);
        token = strtok(NULL, seps);
    }

    printf("\n");

    // (B) 문자열 배열
    // 2차원 char 배열로 여러 문자열을 저장한다.
    char menu[5][10] = {"init", "open", "close", "read", "write"};
    for (int i = 0; i < 5; i++) {
        printf("%d번째 메뉴: %s\n", i, menu[i]);
    }

    printf("\n");

    char fruits[3][20];
    for (int i = 0; i < 3; i++) {
        printf("과일 이름 입력: ");
        // %s는 공백 전까지만 읽는다.
        scanf("%19s", fruits[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("%d번째 과일: %s\n", i, fruits[i]);
    }

    printf("\n");

    // (C) 문자열 포인터 배열
    // 문자열을 포인터로 보관하면 크기가 유연해진다.
    // 리터럴은 읽기 전용이므로 const char*로 선언한다.
    const char *menu2[3] = {"init", "open", "close"};
    for (int i = 0; i < 3; i++) {
        printf("menu2[%d]=%s\n", i, menu2[i]);
    }

    printf("\n");

    // (D) 간단한 사전 검색
    const char *dic[][2] = {
        {"love", "사랑"},
        {"book", "책"},
        {"computer", "컴퓨터"}
    };
    const int ENTRIES = 3;
    char word[20];
    printf("단어를 입력하시오: ");
    scanf("%19s", word);

    int found = 0;
    for (int i = 0; i < ENTRIES; i++) {
        if (strcmp(dic[i][0], word) == 0) {
            printf("%s: %s\n", word, dic[i][1]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("사전에서 발견되지 않았습니다.\n");
    }

    return 0;
}
