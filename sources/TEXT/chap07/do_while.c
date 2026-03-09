#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i = 10;

	do 
	{
		printf("i = %d\n", i);
		i++;	
	} while( i < 3 );
	return 0;
}
