#define _CRT_SECURE_NO_WARNINGS
// 난수 생성 프로그램
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define MAX 45

int main(void)
{
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < 6; i++)
		printf("%d ", 1 + rand() % MAX);
	printf("\n");
	return 0;
}