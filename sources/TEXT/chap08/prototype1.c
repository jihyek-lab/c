#include <stdio.h>
double sub1(double d)
{
        sub2(100.0);
}
double sub2(double d)
{
        sub1(20.0);
}
int main(void)
{
        return 0;
}