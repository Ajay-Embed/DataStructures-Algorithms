#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**************** Sorting Algorithm : Insertion Sort **********************
 *
 * Insertion sort is implemented by using a method called "insertion"
 * 
 * 1. Initially, the first element of the array is assumed to be a sub-array
 *    of a single element which is sorted. (An array of 1 element is sorted) 
 *    
 * 2. Next, it's neighbour is "inserted" to this sub-array by comparing 
 *    it with each member of the sub-array & placing it at the correct 
 *    index (such that all elements on it's left are lesser than it). 
 *
 * 3. On each pass, the very next element (which isn't a part of the 
 *    sub-array) is inserted into a sub-array as per step 2.
 *
 * 4. This process is repeated until all the elements are inserted.
 *    Therefore, upon each insertion, we maintain a sorted array. 
 *    Thus, this sort is useful when a sorted structure needs to be
 *    maintained upon each insertion. 
 *
 * The performance of the algorithm in worst case:
 * (n is the array size)
 *
 * No. of passes = (n-1) 
 * No. of comparisions = 1 + 2 + 3+.....n-1= n(n-1)/2 [O(n^2)]  
 * No. of swaps = 1 + 2 + 3 +......n-1 = n(n-1)/2 [O(n^2)]
 *
 * Worst Case Time Complexity : O(n^2) [^ => Exponentiation]
 *
 * Best Case Time Complexity : O(n) 
 * -> The inner while loop never runs in best case. 
 * -> Therefore (n-1) comparisons & 0 swaps. 
 * 
 * Insertion sort is preferred over bubble sort when dealing with 
 * linked lists, on arrays, both perform almost equally.
 *
 *******************************************************************/ 
void sort_array(int *arr, int len)
{
    if(!arr)
    {
        printf("Illegal array address");
        return;
    }

    for(int i=1; i<len; i++)
    {
        int j=(i-1);

        /* Element to be inserted in sub-array */
        int insert = arr[i];
        
        while((arr[j] > insert) && (j>-1))
        {
            /* If element is greater than insert element, shift it to right */
            arr[j+1] = arr[j];

            /* Move to next element on the left */ 
            j-- ; 
        }

        arr[j+1] = insert;
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
