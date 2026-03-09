#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *pi;
	double *pf;
	char *pc;
	pi = (int *)malloc(sizeof(int));
	pf = (double *)malloc(sizeof(double));
	pc = (char *)malloc(sizeof(char));
	if (pi == NULL || pf == NULL || pc == NULL) { // 반환값이 NULL인지 검사
		printf("동적 메모리 할당 오류\n");
		exit(1);
	}
	*pi = 100;	// pi[0] = 100;
	*pf = 3.14;	// pf[0] = 3.14;

	*pc = 'a';	// pc[0] = 'a';
	free(pi);
	free(pf);	
	free(pc);
	return 0;
}