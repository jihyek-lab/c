#include <stdio.h>
#include <string.h>

/*
[ex03] 문자열 비교/검색
------------------------------------------------------------
핵심
1) strcmp: 사전식 비교 (음수/0/양수)
2) strchr: 문자 1개 검색
3) strstr: 부분 문자열 검색
------------------------------------------------------------
슬라이드 키워드
- 문자열 비교(strcmp/strncmp)
- 문자 검색(strchr)
- 문자열 검색(strstr)
------------------------------------------------------------
*/

int main(void)
{
    // (1) strcmp
    // 반환값: 음수(s1<s2), 0(같음), 양수(s1>s2)
    char s1[80];
    char s2[80];
    int result;

    printf("첫 번째 단어: ");
    // %s는 공백 전까지만 읽는다.
    scanf("%79s", s1);
    printf("두 번째 단어: ");
    scanf("%79s", s2);

    result = strcmp(s1, s2);
    if (result < 0)
        printf("%s가 %s보다 앞에 있음\n", s1, s2);
    else if (result == 0)
        printf("%s와 %s가 같음\n", s1, s2);
    else
        printf("%s가 %s보다 뒤에 있음\n", s1, s2);

    // strncmp: 최대 n글자까지만 비교
    printf("strncmp(s1, s2, 3) = %d\n", strncmp(s1, s2, 3));

    // (2) strchr
    // 찾으면 해당 위치의 포인터, 못 찾으면 NULL
    char s[] = "language";
    char c = 'g';
    char *p = strchr(s, c);
    if (p != NULL) {
        int loc = (int)(p - s);
        printf("'%c' 첫 위치 = %d\n", c, loc);
    } else {
        printf("'%c' 없음\n", c);
    }

    // (3) strstr
    // 부분 문자열의 시작 위치를 찾는다.
    char text[] = "A bird in hand is worth two in the bush";
    char sub[] = "bird";
    char *q = strstr(text, sub);
    if (q != NULL) {
        int loc = (int)(q - text);
        printf("\"%s\"가 %d번째에서 시작\n", sub, loc);
    } else {
        printf("\"%s\" 없음\n", sub);
    }

    return 0;
}
