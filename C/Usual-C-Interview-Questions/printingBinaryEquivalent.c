#include <stdio.h>
#include <stdint.h>


//Printing signed integer as it is
void printBinaryEquivalent(int n)
{
uint32_t k=0;
k = 1 << 31;                //MSB of the k is set

    printf("Binary equivalent for unsigned integer");
    for(int i=0; i<sizeof(int)*8; i++)
    {
        if((n & k>>i) == k>>i)
        {
            printf("1");
        }else
        {
            printf("0");
        }

        if((i+1)%8 == 0)
        printf(" ");
    }

}


//Application
int main(void)
{
int A=0;
printf("Enter the number to check the binary equivalent of  - \n");
scanf("%d", &A);

printBinaryEquivalent(A);

return 0;
}




