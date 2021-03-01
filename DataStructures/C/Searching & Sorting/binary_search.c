#include <stdio.h>
#include <stdlib.h>

/***********************************************
        Binary search in a sorted array
***********************************************/


/**************GLOBAL VARIABLES*****************/
#define SIZE 10
int A[SIZE] = {0,1,2,3,4,5,6,7,8,9};
int low=0, high=9;

/**************** PROTOTYPES ******************/
int Binary_Search_recursive(int low, int high, int key, int *A);
int Binary_Search_iterative(int low, int high, int key, int *A);
void Display(int *A);

/************* IMPLEMENTATIONS ****************/
int Binary_Search_recursive(int low, int high, int key, int *A)
{
    int mid=0;

    if(low <= high)
    {
        mid = ((low+high)/2);

        if(key == A[mid])
        {
            return A[mid];
        }
        else if(key < A[mid])
        {
            return Binary_Search_recursive(low, mid-1, key, A);
        }
        else
        {
            return Binary_Search_recursive(mid+1, high, key, A);
        }
    }

    return -1;
}


int Binary_Search_iterative(int low, int high, int key, int *A)
{
    int mid=0;

    while(low <= high)
    {
        mid = ((low+high)/2);

        if(key == A[mid])
            return mid;

        else if(key < A[mid])
            high = mid-1;

        else
            low = mid+1;
    }

   return -1;
}

void Display(int *A)
{
    int i;

    printf("Elements in the array are \n");
    for(i=0 ; i<SIZE ; i++)
    {
        printf("%d ",A[i]);
    }
}

int main(void)
{

    printf("the element is at index - %d (Recursive)\n", Binary_Search_recursive(low, high, 7, A));
    printf("********************************************************\n");

    printf("the element is at index - %d (Iterative)\n", Binary_Search_iterative(low, high, 8, A));
    printf("********************************************************\n");

    Display(A);

    return 0;
}

