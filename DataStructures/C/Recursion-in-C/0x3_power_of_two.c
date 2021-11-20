/*
    power of two using recursion
*/
#include <stdio.h>

int power_of_two(int x, int exp)
{
    if(exp == 0)
    {
        return 1;
    }
    else
    {
        return (power_of_two(x, exp-1)*x);
    }
}


int main(void)
{
    int x = 5; 
    
    int res = power_of_two(x, 3);
    printf("%d", res);

    return 0;
}
