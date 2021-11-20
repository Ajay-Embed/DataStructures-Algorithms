/*
    3 ways to return the sum of n natural numbers
*/
#include <stdio.h>


//least preferable method
int sum_recursive(int x)
{
    if(x == 0)
    {
        return 0;
    }
    else
    {
        return (sum_recursive(x-1)+x);
    }
}

//okayish preferable method
int sum_iterative(int x)
{
    int i=0, sum=0;
    for(i=1 ; i<=x ; i++)
    {
        sum += i;
    }

    return sum;
}


//most preferable method
int sum(int x)
{
    return ((x*(x-1))/2);
}




int main(void)
{
    int x = 30; 

    //int res = sum_recursive(x);
    //int res = sum_iterative(x);
    int res = sum(x);
    printf("%d", res);

    return 0;
}