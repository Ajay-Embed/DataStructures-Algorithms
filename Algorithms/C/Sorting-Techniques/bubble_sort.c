#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Not too elegant to understand ;) */
#define SWAP(x,y) (x ^= y ^=x ^= y)


/************ Sorting Algorithm : Bubble Sort **********************
 *
 * Bubble sort is a primitive sorting algorithm.
 * It is implemented by comparing two neighbours
 * and swapping if needed them pairwise on each pass. 
 *
 * The performance of the algorithm in worst case:
 * (n is the array size)
 *
 * No. of passes = (n-1) 
 * No. of comparisons = 1 + 2 + 3+.....n-1= n(n-1)/2 [O(n^2)]
 * No. of swaps = 1 + 2 + 3 +......n-1 = n(n-1)/2 [O(n^2)]
 *
 * Worst Case Time Complexity : O(n^2) [^ => Exponentiation]
 * Best Case Time Complexity : O(n) [Due to the "little optimation"]
 *
 *******************************************************************/ 
void sort_array(int *arr, int len)
{
    if(!arr)
    {
        printf("Illegal array address");
        return;
    }

    bool isSwap=false;

    for(int i=0; i<len-1; i++)
    { 
        /* Little optimization : Set the flag to false before a pass */ 
        isSwap=false;

        for(int j=0; j<(len-1-i); j++)
        {
            if(arr[j] > arr[j+1])
            {
                /* Swap neighbours */
                SWAP(arr[j], arr[j+1]); 

                /* Set the flag when swapped */
                isSwap=true; 
            }
        }
        
        if(isSwap == false)
        {
            /* If nothing was swapped, the array is sorted */ 
            break; 
        }
    }
}


void print_array(int *arr, int len)
{ 
    if(!arr)
    {
        printf("Illegal array address");
        return;
    }


    for(int i=0 ; i<len ; i++)
    {
        printf(" %d", *(arr+i)); 

    }
}

int main(void)
{
    int n = 0; 

    printf("Enter the number of elements in the array : ");
    scanf("%d", &n); 
    
    int *arr = malloc(n*sizeof(int)) ;
    
    if(arr)
    {
        printf("\r\nEnter array elements: ");
        for (int i=0; i<n; i++)
        {
            printf("\r\nEnter element %d : ", i); 
            scanf("%d", (arr+i));
        }
    
        printf("\r\nYour input array :"); 
        print_array(arr, n);

        sort_array(arr,n);
        
        printf("\r\nSorted array :"); 
        print_array(arr, n);


    }

    else 
        printf("Malloc Failed!"); 

}
