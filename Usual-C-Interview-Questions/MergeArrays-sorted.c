                /*******************************************************************************************************
                Program to merge two sorted arrays and create a resultant sorted array without using a sorting algorithm
                ********************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

int* MergeAndSort(int *A, int A_length,  int *B, int B_length, int res_array_length)
{
    int i=0, j=0, k=0;

    //array to store the result of merge and sort of A & B
    int *C = (int *)malloc(sizeof(int)*(res_array_length));

    while(i<A_length && j<B_length)
    {
        if(A[i] < B[j])
        {
            C[k++] = A[i++];
        }else
        {
            C[k++] = B[j++];
        }
    }

    //Let i be where it was and completely store the rest of the elements if any left in C
    for( ; i<A_length ; i++)
    {
        C[k++] = A[i];
    }

    //Let j be where it was and completely store the rest of the elements if any left in C
    for( ; j<B_length ; j++)
    {
        C[k++] = B[j];
    }

    return C;
}


int main(void)
{
    int A[4] = {5,7,9,14};
    int B[5] = {1,6,8,12,13};

    int A_length = sizeof(A)/sizeof(int);
    int B_length = sizeof(B)/sizeof(int);
    int C_length = A_length + B_length;

    printf("A_length = %d\n", A_length);
    printf("B_length = %d\n", B_length);


    int *ptr = MergeAndSort(A, A_length, B, B_length, C_length);

    //Merged and sorted
    for(int i=0 ; i< C_length ; i++)
    {
        printf("\n\n%d ", ptr[i]);
    }

    free(ptr);
    ptr = NULL;

    return 0;
}
