#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* Not too elegant to understand ;) */
#define SWAP(x,y) (x ^= y ^=x ^= y)


/**************** Sorting Algorithm : Insertion Sort **********************
 *
 * The idea behind selection sort is based on selecting a particular index,
 * and finding a minimum element to sit on that index. For example, you 
 * have an empty seat in the front row & you've to select a person with
 * minimal height to occupy that seat in a hall full of people. 
 * 
 * The algorithm: 
 *
 * 1. Initially, we start with index i=0, and find the min. element from
 *    i+1 to n (where n is the length of the list). 
 *    
 * 2. On finding the min element, we swap it with the element present 
 *    at index i. 
 *
 * 3. In the next pass/iteration, the very next index is chosen (i=i+1)
 *    and the process is repeated. 
 *
 * 4. This process is repeated until i=n-1. 
 *    Therefore, upon each iteration, the first i elements are sorted. 
 *
 * The performance of the algorithm in worst case:
 * (n is the array size)
 *
 * No. of passes = (n-1) 
 * No. of comparisons = 1 + 2 + 3+.....n-1= n(n-1)/2 [O(n^2)]
 * No. of swaps = (1 x n) [Single swap per iteration] [O(n)]
 *
 * Efficient in terms of swap operations. 
 *
 * Worst Case Time Complexity : O(n^2) [^ => Exponentiation]
 *
 * Best Case Time Complexity : O(n^2) [Both nested loops run always]
 *
 *******************************************************************/ 
void sort_array(int *arr, int len)
{
    if(!arr)
    {
        printf("Illegal array address");
        return;
    }

    int j,k; 

    for(int i=0; i<len-1; i++)
    {
        for((j = k = i); j<len; j++)
        {
            if(arr[j] < arr[k])
            {
                k=j; 
            }
        }
       
        SWAP(arr[i], arr[k]); 
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
