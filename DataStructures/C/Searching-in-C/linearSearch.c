//Implementation of a simple linear search

#include <stdio.h>


/*
    Param1 = Array to be searched
    Param2 = Length of the Array
    Param3 = Value of the key element to be found in the array

*/

void LinearSearch(int *A, int len, int key)
{
    int i=0;
    
    for(i=0 ; i<len ; i++)
    {
        if(A[i] == key)
        {
            printf("Element found at %d index!", i);
            break;
        }
    }
    
}




int main(void)
{
    int A[10] = {5,2,3,6,4,2,6,8,3,7};
    printf("The Elements in the array are - \n");
    
    for(int i=0 ; i<10 ; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
    
    printf("Enter the key value ? \n");
    int x=0;
    scanf("%d", &x);
    
    int size_array = sizeof(A)/sizeof(A[0]);
    
    LinearSearch(A, size_array, x);

    return 0;
}