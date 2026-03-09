#include <stdio.h>
int main(void)
{
	int i;
	double *pd;
	pd = &i;
	*pd = 36.5;
	return 0;
}