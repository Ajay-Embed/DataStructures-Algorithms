/******************************************************************************

Problem statement - Read an integer N and then read that many integers inside 
                    an array. Print YES if the entered array is increasing

*******************************************************************************/

#include <stdio.h>

typedef struct {
    int *A;
    int size;
}Array_t;


//Get the array from the user
void GetArray(Array_t *Arr)
{
    int n=0;
    printf("Enter the number of elements you want to enter in the array\n");
    scanf("%d", &n);
    
    Arr->size = n;
    
    for(int i=0 ; i<Arr->size ; i++)
    {
        printf("Enter number at array index %d - ", i);
        scanf("%d", &Arr->A[i]);
    }
    
    //Display the entered array to the user once
    printf("The array you entered is -  ");
    for(int i=0 ; i<Arr->size ; i++)
    {
        printf("%d ", Arr->A[i]);
    }
    
    printf("\nChecking if the array is in icreasing order of elements ...\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n");
}

//1,2,3,4,5

//Check if the array entered is in increasing order or not?
void CheckIncreasing(Array_t Arr)
{
    int flag=0;
    
    for(int i=1 ; i<Arr.size ; i++)
    {
        if(Arr.A[i] < Arr.A[i-1])
        {
            flag=1;
            break;
        }
    }
    
    if(flag==1)
    {
        printf("NO");
    }else
    {
        printf("YES");
    }
}



int main(void)
{
    Array_t Arr;
    
    GetArray(&Arr);
    
    CheckIncreasing(Arr);

    return 0;
}
