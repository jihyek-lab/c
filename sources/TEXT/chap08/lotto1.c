#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int i;

	for(i = 0; i < 6; i++)
		printf("%d ", rand());
	printf("\n");
	return 0;
}