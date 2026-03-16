#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
[ex07] 문자열 응용: 단어 수, 암호 검사, 퀴즈, 암호화, 행맨
------------------------------------------------------------
파트 A) 단어 수 세기
파트 B) 암호 강도 검사
파트 C) 단답형 퀴즈
파트 D) 간단한 시저 암호(문자 이동)
파트 E) 행맨(간단 버전)
------------------------------------------------------------
슬라이드 키워드
- 단어 세기
- 유효한 암호 검사
- 문자열 비교(퀴즈)
- 시저 암호
- 행맨
------------------------------------------------------------
*/

static void read_line(char *buf, int size)
{
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    // 마지막 개행 제거
    buf[strcspn(buf, "\n")] = '\0';
}

int count_word(const char *s)
{
    int wc = 0;
    int waiting = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha((unsigned char)s[i])) {
            if (waiting) {
                wc++;
                waiting = 0;
            }
        } else {
            waiting = 1;
        }
    }
    return wc;
}

int check_password(const char *pass)
{
    int lower = 0, upper = 0, digit = 0;
    int len = (int)strlen(pass);
    // 길이 7 이상 + 소문자/대문자/숫자 포함
    if (len < 7) return 0;
    for (int i = 0; i < len; i++) {
        if (islower((unsigned char)pass[i])) lower = 1;
        if (isupper((unsigned char)pass[i])) upper = 1;
        if (isdigit((unsigned char)pass[i])) digit = 1;
    }
    return lower && upper && digit;
}

void encrypt(char *cipher, int shift)
{
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (cipher[i] >= 'a' && cipher[i] <= 'z') {
            cipher[i] = (char)(cipher[i] + shift);
            // 알파벳 범위를 넘으면 다시 앞쪽으로
            if (cipher[i] > 'z') cipher[i] = (char)(cipher[i] - 26);
        } else if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            cipher[i] = (char)(cipher[i] + shift);
            if (cipher[i] > 'Z') cipher[i] = (char)(cipher[i] - 26);
        }
    }
}

void init_answer(const char *solution, char *answer)
{
    // 글자는 '_'로, 공백은 그대로 유지
    for (int i = 0; solution[i] != '\0'; i++) {
        answer[i] = (solution[i] == ' ') ? ' ' : '_';
    }
    answer[strlen(solution)] = '\0';
}

int update_answer(const char *solution, char *answer, char ch)
{
    int changed = 0;
    for (int i = 0; solution[i] != '\0'; i++) {
        if (solution[i] == ch) {
            answer[i] = ch;
            changed = 1;
        }
    }
    return changed;
}

int main(void)
{
    char buf[200];

    // (A) 단어 수 세기
    printf("문장을 입력하시오: ");
    read_line(buf, sizeof(buf));
    // 영문자 연속 구간을 단어로 본다.
    printf("단어 수 = %d\n\n", count_word(buf));

    // (B) 암호 검사
    printf("패스워드를 입력하시오: ");
    read_line(buf, sizeof(buf));
    if (check_password(buf)) printf("강한 암호입니다.\n\n");
    else printf("유효한 암호가 아닙니다.\n\n");

    // (C) 단답형 퀴즈
    const char *key = "C";
    do {
        printf("임베디드 장치에 가장 많이 사용되는 언어는? ");
        read_line(buf, sizeof(buf));
    } while (strcmp(key, buf) != 0);
    printf("맞았습니다!\n\n");

    // (D) 간단한 암호화
    printf("암호화할 문자열을 입력하시오: ");
    read_line(buf, sizeof(buf));
    encrypt(buf, 3);
    printf("암호화된 문자열: %s\n\n", buf);

    // (E) 행맨(간단 버전)
    // 대소문자를 구분하며, 한 글자만 입력으로 사용한다.
    const char *solution = "meet at midnight";
    char answer[100];
    int attempts = 6;
    init_answer(solution, answer);

    while (attempts > 0) {
        printf("현재 상태: %s\n", answer);
        printf("글자를 추측하시오 (남은 기회 %d): ", attempts);
        read_line(buf, sizeof(buf));
        if (buf[0] == '\0') continue;

        // 한 글자만 사용
        if (!update_answer(solution, answer, buf[0])) {
            attempts--; // 맞추지 못하면 기회 감소
        }

        if (strcmp(solution, answer) == 0) {
            printf("정답! %s\n", answer);
            return 0;
        }
    }

    printf("실패! 정답은: %s\n", solution);
    return 0;
}
