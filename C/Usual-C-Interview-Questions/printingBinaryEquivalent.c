#include <stdio.h>
#include <stdint.h>

//Descriptive MACROS
#define MSB_OF_THE_BYTE                          31
#define NUMBER_OF_BITS_IN_STANDARD_INTEGER       sizeof(int)*8
//Printing signed integer as it is
void printBinaryEquivalent(int n)
{
uint32_t k=0;

k = 1 << MSB_OF_THE_BYTE;                //MSB of the k is set

    printf("Binary equivalent for unsigned integer");
    for(int i=0; i<NUMBER_OF_BITS_IN_STANDARD_INTEGER; i++)
    {
        if((n & k>>i) == k>>i)
        {
            printf("1");
        }else
        {
            printf("0");
        }

        //To make the binary look good
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




