#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int i = 3000;
	int *p=NULL;	

	p = &i;	
	

	printf("i = %p\n", i);	// 변수의 값 출력
	printf("&i = %p\n\n", &i);	// 변수의 주소 출력

	printf("p = %d\n", p);	// 포인터의 값 출력
	printf("*p = %d\n", *p);	// 포인터를 통한 간접 참조 값 출력

	return 0;
}	