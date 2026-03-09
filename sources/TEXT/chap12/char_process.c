#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main( void )
{
	int c;

	while((c = getchar()) != EOF)
	{
		if( islower(c) )
			c = toupper(c);
		putchar(c);
	}
	return 0;
}
