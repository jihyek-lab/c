#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// 이것을 반드시 포함하여야 한다. 

int main(void) {
	double result, value = 1.6;

	result = floor(value);		// result는 1.0이다. 
	printf("%lf ", result);
	result = ceil(value);		// result는 2.0이다. 
	printf("%lf ", result);
	return 0;
}