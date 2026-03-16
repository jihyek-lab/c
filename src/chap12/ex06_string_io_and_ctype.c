#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
[ex06] 문자/문자열 입출력 + ctype
------------------------------------------------------------
핵심
1) getchar/putchar는 한 글자씩 입출력한다.
2) fgets/puts는 한 줄 문자열 입출력에 유용하다.
   (Windows 교재의 gets_s는 여기서 fgets로 대체)
3) ctype 함수로 문자 검사/변환이 가능하다.
4) _getch/_putch는 Windows 전용(conio.h) 함수라 여기선 사용하지 않는다.
------------------------------------------------------------
슬라이드 키워드
- 문자 입출력(getchar/putchar)
- 문자열 입출력(fgets/puts)
- 문자 처리(ctype)
------------------------------------------------------------
*/

int main(void)
{
    // (1) getchar/putchar: EOF까지 그대로 출력
    // 입력 종료: macOS 터미널은 Ctrl+D
    int ch;
    printf("Type characters (Ctrl+D to end):\n");
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }

    // EOF가 설정되었으므로 다음 입력을 위해 상태를 초기화
    clearerr(stdin);

    // (2) fgets/puts: 한 줄 입력/출력
    char line[100];
    printf("\nEnter a line: ");
    if (fgets(line, sizeof(line), stdin) != NULL) {
        puts("You typed:");
        puts(line);
    }

    // (3) ctype: 소문자를 대문자로
    char s[] = "abcdefABCDEF";
    for (int i = 0; s[i] != '\0'; i++) {
        if (islower((unsigned char)s[i])) {
            s[i] = (char)toupper((unsigned char)s[i]);
        }
    }
    printf("upper = %s\n", s);

    return 0;
}
