#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char* p;
	int size = 10, index = 0;		// size= 동적 배열의 크기, index= 현재 저장 위치
	char c;

	p = (char*)malloc(size * sizeof(char));
	if (p == NULL) {
		printf("malloc 오류\n");
		exit(1);
	}
	printf("입력할 문자열=");
	do {
		c = getchar();
		if (index >= (size - 1)) {	// NULL 문자를 저장해야 하므로 1을 뺀다.
			size *= 2;    // realloc()은 값비싼 연산이므로 한 번에 2배씩 증가한다. 
			p = (char*)realloc(p, sizeof(char) * size);
			if (p == NULL) {
				printf("realloc 오류\n");
				exit(1);
			}
		}
		p[index++] = c;
	} while (c != '\n');
	p[index] = NULL;

	printf("입력된 문자열=%s \n", p);
	return 0;
}