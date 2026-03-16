#include <stdio.h>
#include <string.h>

/*
[ex02] 문자열 길이/복사/붙이기
------------------------------------------------------------
핵심
1) strlen: 문자열 길이(\0 제외)
2) strcpy: 문자열 복사 (dest 크기 주의)
3) strcat: 문자열 이어 붙이기 (dest 크기 주의)
------------------------------------------------------------
슬라이드 키워드
- 문자열 길이
- strcpy/strcat
- strncpy/strncat
------------------------------------------------------------
*/

int main(void)
{
    char src[] = "Action speaks louder than words";
    char dst[100];

    // (1) 문자열 길이
    // strlen은 '\\0'을 제외한 길이를 반환한다.
    printf("src length = %zu\n", strlen(src));

    // (2) 문자열 복사
    // dst 크기가 충분해야 안전하다.
    strcpy(dst, src);
    printf("dst = %s\n", dst);

    // (3) 문자열 이어 붙이기
    // 여러 번 붙이므로 버퍼 크기에 주의한다.
    char buffer[80] = "Hello world from ";
    strcat(buffer, "strcpy ");
    strcat(buffer, "and ");
    strcat(buffer, "strcat!");
    printf("buffer = %s\n", buffer);

    // (4) 길이 제한 버전
    // strncpy/strncat은 최대 n개 문자만 처리한다.
    // strncpy는 \\0을 자동으로 넣지 않을 수 있으므로 직접 처리한다.
    char safe[10] = "";
    strncpy(safe, "HelloWorld", sizeof(safe) - 1);
    safe[sizeof(safe) - 1] = '\0';
    strncat(safe, "!!!", sizeof(safe) - strlen(safe) - 1);
    printf("safe = %s\n", safe);

    return 0;
}
