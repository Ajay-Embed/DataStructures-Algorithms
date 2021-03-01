
#include <stdio.h>
#include <stdlib.h>
/*
In this program we will find duplicates in a given string using a hash table
1. Assume the string is in lowercase
2. Initialize a hash table with 26 elements to zero
3. a is 97 in ASCII........z is 122.
4. Since the aplhabets are small, whenever we reach a character subtract 97 from it, this way we will reach the index of the particular character.
5. Increment accordingly in the hash table as well.
6. Time complexity - O(n)
*/

//Core logic implementation
void check_duplicate(char *str)
{
    int hash[26] = {0}, i=0;

    while(str[i] != '\0')
    {
        hash[str[i]-97]++;
        i++;
    }

    for(i=0 ; i<26 ; i++)
    {
        if(hash[i] > 1)
        {
            printf("%c is a duplicate", hash[i]);
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
