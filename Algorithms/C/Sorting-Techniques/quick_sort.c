#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 99999

/**************** Sorting Algorithm : Insertion Sort **********************
 *
 * Quick sort is based on a similar idea as selection sort. In selection 
 * sort, we choose an index and find an element that can sit on that index
 * whereas, in quick sort, we choose an element and find an index for it. 
 * 
 * 
 * The algorithm: 
 *
 * -----------------------Partitioning Algorithm---------------------------
 *
 * 1. Initially, we start with an index called "pivot", the idea is all 
 *    elements on the right & left of pivot shall sit sorted.  
 *    
 * 2. Next, we scan the list from either ends, using indices i & j. 
 *    The elements at index i shall be <= element at pivot & the element
 *    at index j shall be > element at pivot. In case any of these fail
 *    we swap elements at i & j (if i<j). After scanning through the list
 *    elements at index j & pivot are swapped. This way we find the correct
 *    index for the pivot element.
 *
 * 3. Steps 1 & 2 implement a method called "partitioning". This process
 *    partitions the array in a way that all the elements on the left 
 *    of pivot are less that it, and on the right are greater than it. 
 *-------------------------------------------------------------------------
 *
 * 4. Therefore, every execution of the partitioning algorithm places 
 *    one element in the sorted position/index.
 *
 * 5. Thus, we recursively keep partitioning the sub-arrays on the right
 *    and left side of the pivot index. 
 *
 * Efficient in terms of swap operations. 
 *
 * Worst Case Time Complexity : O(n^2) [^ => Exponentiation]
 *
 * Best Case Time Complexity : O(nlogn)
 *
 *******************************************************************/ 
void SWAP(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition (int *arr, int low_index, int high_index)
{
    int pivot = arr[low_index]; 
    int i = low_index; 
    int j = high_index; 
    
    do
    {
        do
        {
            i++;

        }while(arr[i]<=pivot);
        
        do
        {
            j--;
            
        }while(arr[j]>pivot); 

        if(i<j)
        {
            SWAP(&arr[i], &arr[j]); 
        }

    }while(i<j);
    
    /* Swap pivot */
    SWAP(&arr[low_index], &arr[j]); 
    
    /* Return index of the sorted element (pivot) */ 
    return j; 
}

void sort_array(int *arr, int low_index, int high_index)
{
    if(!arr)
    {
        printf("Illegal array address");
        return;
    }

    int pivot; 

    if(low_index < high_index)
    {
        pivot = partition(arr, low_index, high_index); 
        sort_array(arr, low_index, pivot);
        sort_array(arr,pivot+1, high_index); 
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
    
    int *arr = malloc((n+1)*sizeof(int)) ;
    
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
        
        /* End of array delimiter */
        arr[n] = MAX; 

        sort_array(arr,0,n);
        
        printf("\r\nSorted array :"); 
        print_array(arr, n);


    }

    else 
        printf("Malloc Failed!"); 

}
