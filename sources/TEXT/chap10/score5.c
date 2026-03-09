#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{

       int i;
       int scores[5] = { 31, 63, 62, 87, 14 };
 
       for(i = 0; i < 5; i++)
             printf("scores[%d] = %d\n", i, scores[i]);
 
       return 0;
}