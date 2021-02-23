//program to swap the bits of a given integer.
/*
For eg given number 10110101

get it in a pair of 00001111 11001010 10101010 01110001

NOW 0xAAAAAAAA is number that has all the even bits set.
AND 0x55555555 is a number that has all the odd bits set


Extract all the bits that were even bits in our number by masking our numeber with 0xAAAAAAAA.
Extract all the bits that were odd bits in our number by masking our numeber with 0x55555555.

Now right shift even bits by 1 and left shift odd bits by 1. Then Merge :)


*/


#include <stdio.h>
#include <stdint.h>

#define EVEN_MASK       0xAAAAAAAA
#define ODD_MASK        0x55555555


int main()
{
    uint32_t var = 0xDEADBEEF;
    
    uint32_t even_extract = var & EVEN_MASK;
    
    uint32_t odd_extract = var & ODD_MASK;
    
    even_extract >>= 1;
    odd_extract <<= 1;
    
    uint32_t SwappedAdjacentbits = even_extract | odd_extract;
    
    printf("%X", SwappedAdjacentbits);
    return 0;
    
}
//Result   = 11 10 11 01 01 01 11 10 01 11 11 01 11 01 11 11
//Original = 11 01 11 10 10 10 11 01 10 11 11 10 11 10 11 11


