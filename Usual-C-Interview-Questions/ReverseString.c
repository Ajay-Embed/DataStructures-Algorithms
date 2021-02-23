
#include <stdio.h>
#include <stdlib.h>

void Reverse_inPlace(char A[])
{
    char B[10] = {0};
    char temp;

    int j=0;

    for(j=0 ; A[j] != '\0' ; j++)
    {}

    j -= 1;

    for(int i=0 ; i<j ; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    printf("%s", A);
}

void Reverse_Using_AuxiliaryArray(A)
{
//Take an auxiliary array and copy the elements of the string to it and then reverse copy it back
//into the original string
}

int main(void)
{

    char A[] = "HelloWorld";
    Reverse_inPlace(A);

    //Reverse_Using_AuxiliaryArray(A);
    return 0;
}












