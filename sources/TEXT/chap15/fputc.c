#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp = NULL;

	fp = fopen("sample.txt", "w");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}
	else
		printf("파일 열기 성공\n");
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fclose(fp);
	return 0;
}