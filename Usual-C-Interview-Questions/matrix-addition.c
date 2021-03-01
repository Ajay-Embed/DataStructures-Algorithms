//Adding two 4x4 matrices 


#include <stdio.h>

int main()
{
    int A[4][4], B[4][4], res[4][4];
    int r=0, c=0;
    
    printf("Matrx addition\n");
    
    printf("Enter the digits for the first matrix\n");
    
    for(r=0 ; r<4 ; r++)
    {
        for(c=0 ; c<4 ; c++)
        {
            scanf("%d", &A[r][c]);
        }
    }
    
    printf("Enter the digits for the second matrix\n");
    
    for(r=0 ; r<4 ; r++)
    {
        for(c=0 ; c<4 ; c++)
        {
            scanf("%d", &B[r][c]);
        }
    }
    
    
    printf("Adding the matrix");
    printf(".\n"); printf(".\n"); printf(".\n"); printf(".\n"); printf(".\n"); printf(".\n"); printf(".\n"); printf(".\n");

    for(r=0 ; r<4 ; r++)
    {
        for(c=0 ; c<4 ; c++)
        {
            res[r][c] = A[r][c] + B[r][c];
        }
    }
    
    printf("The resultant matrix is \n");
    
    for(r=0 ; r<4 ; r++)
    {
        for(c=0 ; c<4 ; c++)
        {
            printf("%d ", res[r][c]);
        }
        
        printf("\n");
    }
    
    

    return 0;
}
