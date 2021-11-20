/*
    Factorial using recursion
*/
#include <stdio.h>

int factorial(int x)
{
    if(x == 0)
    {
        return 1;
    }
    else
    {
        return (factorial(x-1)*x);
    }
}


int main(void)
{
    int x = 5; 

    int res = factorial(x);
    printf("%d", res);

    return 0;
}
