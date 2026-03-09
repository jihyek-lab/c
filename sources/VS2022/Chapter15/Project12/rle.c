#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        FILE* fp1 = fopen("test.txt", "r");	// 텍스트 파일을 가정한다. 
        FILE* fp2 = fopen("result.txt", "w");
        if (fp1 == NULL || fp2 == NULL) {
                printf("파일 오픈 오류\n");
                exit(1);
        }
        char curr_ch = 0, prev_ch = 0;	// 현재 문자와 이전 문자
        int count = 0;

        while (1) {
                int i = fread(&curr_ch, sizeof(char), 1, fp1);
                if (feof(fp1)) {	// 파일의 끝이면
                        fprintf(fp2, "%d%c", count, prev_ch);
                        break;
                }
                if (prev_ch != curr_ch && prev_ch != 0) {  // 이전 문자와 현재 문자가 다르면
                        fprintf(fp2, "%d%c", count, prev_ch);
                        count = 1;
                }
                else count++;
                prev_ch = curr_ch;
        }
        fclose(fp1);
        fclose(fp2);
        return 0;
}