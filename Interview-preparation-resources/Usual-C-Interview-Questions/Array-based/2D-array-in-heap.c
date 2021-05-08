#include <stdio.h>
#include <stdlib.h>

/****************************************************
    Creating a (3x4) 2D array in heap
****************************************************/
int main(void)
{
    int r=0, c=0;
    // Pointer in stack that keeps track of the array elements
    int **Arr;

    Arr = (int **)malloc(sizeof(int*)*3);

    *(Arr+0) = (int *)malloc(sizeof(int)*4);
    *(Arr+1) = (int *)malloc(sizeof(int)*4);
    *(Arr+2) = (int *)malloc(sizeof(int)*4);


    //Filling it up
    for(r=0; r<3; r++)
    {
        for(c=0; c<4; c++)
        {
            Arr[r][c] = 11;
        }

    }

    //Displaying the array
    for( r=0; r<3; r++)
    {
        for(c=0; c<4; c++)
        {
            printf("%d ", Arr[r][c]);
        }
    printf("\n");
    }


    free(Arr);


    return 0;
}

