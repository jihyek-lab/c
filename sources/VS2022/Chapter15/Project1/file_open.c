#define _CRT_SECURE_NO_WARNINGS
// 파일 열기 
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

	fclose(fp);

	return 0;
}
