#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main(void)
{
	char s[] = "Man is immortal, because he has a soul";
	char seps[] = " ,\t\n";
	char* token;

	token = strtok(s, seps);

	while (token != NULL) {
		printf("ÅäÅ«: %s\n", token);
		token = strtok(NULL, seps);
	}
	return 0;
}