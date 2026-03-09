#include <stdio.h>
typedef union {
        struct {
                unsigned char b1 : 1;
                unsigned char b2 : 1;
                unsigned char b3 : 1;
                unsigned char b4 : 1;
                unsigned char reserved : 4;
        } bits;
        unsigned char byte;
} HW_Register;
int main(void)
{
        volatile HW_Register* reg = (volatile HW_Register*)0xE002C000;
        reg->bits.b2 = 1; // LED를 켠다.
        return 0;
}