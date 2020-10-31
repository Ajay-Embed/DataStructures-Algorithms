
#include <stdio.h>
#include <stdint.h>

//#define TAIL
//#define HEAD

void recursion(uint8_t x)
{
#ifdef TAIL
    //base condition
    if(x>0)
    {
        printf("Hi %u \n", x);
        recursion(x-1);
    }
#endif

#ifdef HEAD
    //base condition
    if(x>0)
    {
        recursion(x-1);
        printf("Hi %u \n", x);
    }
#endif
}


int main(void)
{
    uint8_t x = 3;
    recursion(x);
    return 0;
}
