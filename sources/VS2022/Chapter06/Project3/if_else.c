#define _CRT_SECURE_NO_WARNINGS
// if-else 문을 이용하여 홀수와 짝수를구분한다.
#include <stdio.h>

int main(void)
{
	int number;

	printf("정수를 입력하시오:");
	scanf("%d", &number);

	if (number % 2 == 0)
		printf("입력된 정수는 짝수입니다.\n");
	else
		printf("입력된 정수는 홀수입니다.\n");

	return 0;
}
