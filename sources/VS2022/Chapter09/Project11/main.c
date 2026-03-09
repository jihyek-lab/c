#include <stdio.h>


extern unsigned random_i(void);
extern double random_f(void);

extern int MOD;

int main(void)
{
	int i;

	MOD = 32727;
	for (i = 0; i < 10; i++)
		printf("%d ", random_i() % 100);
	printf("\n");
	return 0;
}