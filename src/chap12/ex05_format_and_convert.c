#include <stdio.h>
#include <stdlib.h>

/*
[ex05] 문자열 포맷/변환
------------------------------------------------------------
핵심
1) sprintf: 숫자를 문자열로 포맷
2) sscanf: 문자열에서 형식에 맞게 읽기
3) atoi/atof: 문자열을 숫자로 변환
------------------------------------------------------------
슬라이드 키워드
- sprintf/sscanf
- 문자열 수치 변환(atoi/atof)
------------------------------------------------------------
*/

int main(void)
{
    // (1) sprintf
    // 숫자를 문자열로 포맷해 buffer에 저장
    // 버퍼 크기를 넘지 않도록 주의한다(필요하면 snprintf 사용).
    char buffer[100];
    int x = 10, y = 20;
    int result = x + y;
    sprintf(buffer, "정수 %d와 %d의 합 = %d", x, y, result);
    printf("%s\n", buffer);

    // (2) sscanf
    // 문자열에서 형식에 맞게 값을 읽어온다.
    char instring[] = "file 12";
    char name[10];
    int number;
    sscanf(instring, "%9s %d", name, &number);
    printf("name = %s, number = %d\n", name, number);

    // (3) atoi/atof
    // 숫자 형태의 문자열을 int/double로 변환한다.
    char s1[] = "100";
    char s2[] = "12.93";
    int i = atoi(s1);
    double d = atof(s2);
    printf("atoi: %d, atof: %.2f\n", i, d);

    return 0;
}
