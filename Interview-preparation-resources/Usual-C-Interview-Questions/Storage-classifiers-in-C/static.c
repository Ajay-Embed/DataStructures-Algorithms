#include<stdio.h>

/************************************************************************************
        A short snippet for the essence of using static storage classifier in C.

        Also do check check out the other ones in the list for

        extern, auto & register.
************************************************************************************/


/***********************************************************************************
    This function returns the reference of the array that is local to the function.

    If the array declared inside the function was not static, then we wouldn't have
    been able to print it onto the console via main() method.
    Because once the function
    is off the function-call-stack, then contents of the function are destroyed, unless
    the members are declared static.
    If declared static, they will be preserved for
    the remainder of the program execution.

************************************************************************************/
int* array()
{
    static int arr[5] = {2,3,5,7,11};

    //return address of the array
    return arr;
}



//Application
int main(void)
{
    int x = -1;
    printf("Press 1 to see the array \n");
    scanf("%d", &x);

    int* arr = NULL;;

    arr = array();

    if(x == 1)
    {
       for(int i=0 ; i<5 ; i++)
       {
            printf("%d, ", *(arr+i));
       }
    }
    else
    {
        printf("huh");
    }

    return 0;
}
