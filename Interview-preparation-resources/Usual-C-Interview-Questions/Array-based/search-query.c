/******************************************************************************

Problem statement - Search for a query in an Array_t
                  ------------------------------------------------------------------------------------------------------------
                  
    ----->>>        Read an array from the user that has N(< 200 integers) elements (0 <= A[i] <= 500)
                    
                    Then read a query from the user for example - 3
                    
                    As the user entered 3 that means he can now search for 3 elemnts in the array
                    
                    print the number if the number exists in the array or return 0 if the number doesnot exist in the array
                  ------------------------------------------------------------------------------------------------------------
                  
                  
Constraint        - Do not use nested loops 
                  - Do not sort the array
                  - Do not alter the contents of the orginal array
                  
                  - Space complexity is not an issue but T.C should be roughly O(N).
                  
*******************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void)
{
    printf("Enter the number of elements in the array\n");
    int N=0;
    scanf("%d", &N);
    
    printf("Enter the number of queries\n");
    int Q=0;
    scanf("%d", &Q);
    
    //create an array of 501 elements because maximum value of A[i] can be between 0 to 500
    int *A = (int *)malloc(sizeof(int)*501);
    
    printf("Enter the elements in the array\n");
    //First fill all the elements with -1
    for(int i=0 ; i<N ; i++)
    {
        A[i] = -1;
    }
    
    //Now ask the user to enter the value of the elements in the array & fill it in the index pertaining to tha value
    int value=0;
    for(int i=0 ; i<N ; i++)
    {
        scanf("%d", &value);
        
        //we are doing this to make the query easier & to avoid nested loops
        A[value] = value;
    }
    
    
    int val=0;
    //query process
    while(Q--)
    {
        printf("\nEnter the number you wish to query from the array\n");
        scanf("%d", &val);
        
        printf("%d", A[val]);
    }
    
    
    return 0;
}

