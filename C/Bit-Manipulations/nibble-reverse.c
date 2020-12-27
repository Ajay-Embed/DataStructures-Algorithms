#include <stdio.h>
#include <stdint.h>

int main (void)
{
    uint32_t x = 0xDEADBEEF;
    printf("original 4 bytes %X\n", x);
    
    uint32_t y = 0;

    for(uint8_t i = 0 ; i < 32 ; i += 4)
    {
        y <<= 4;
        y |= x>>i & 0xF;
    }
    
    printf("reverse order nibbles %X\n", y);

return 0;
}


