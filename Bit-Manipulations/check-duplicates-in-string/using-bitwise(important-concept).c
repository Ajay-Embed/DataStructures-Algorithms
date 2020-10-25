
#include <stdio.h>
#include <stdint.h>
/*
In this program we will find duplicates in a given string using bit-wise operations

*/

//Core logic implementation
void check_duplicate(char *str)
{
    uint32_t x=0;
    uint32_t y=1, k=0;

    for(int i=0 ; str[i] != '\0' ; i++)
    {
        y = 1;
        k = str[i] - 97;        //Getting the index of the character in the array
        y <<= k;                //set the correspoding bit in uint32_t y

        if((x & y) == y)
        {
            //the character is reperating character
            printf("%c is a repeating character", str[i]);
        }
        else
        {
            //perform the merge so as to set the bit
            x |= y;
        }
    }
}


//Application
int main()
{
    char s[100];
    scanf("%[^\n]s", s);

    check_duplicate(s);

    return 0;
}
