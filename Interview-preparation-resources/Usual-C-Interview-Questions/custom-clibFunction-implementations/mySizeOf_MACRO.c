#include<stdio.h>
#include<stdint.h>

#define SIZEOF(data) ((uint8_t *)(&data + 1U) - (uint8_t*)(&data))


int main(void)
{
    short x;
    
    printf("%ld", SIZEOF(x));
    
    return 0;
}