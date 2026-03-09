#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	volatile char* p = (volatile char*)0x30000000;
	int i;
	while (1) {
		*p |= 0x1;		// 첫 번째 비트를 1로 만든다. 다른 비트들은 건드리지 않는다. 
		for (i = 0; i < 100000; i++);	// 시간 지연 루프
		*p &= ~(0x1);	// 첫 번째 비트를 0로 만든다. 다른 비트들은 건드리지 않는다. 
		for (i = 0; i < 100000; i++);	// 시간 지연 루프
	}
	return 0;
}