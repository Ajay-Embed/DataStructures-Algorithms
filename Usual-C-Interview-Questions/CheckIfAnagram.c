#include <stdio.h>
#include <stdlib.h>

/***************************************************************************************************************
            Program to check if two strings are anagram or not using hashing
            TC - O(n)
***************************************************************************************************************/

void IsAnagram(char *str1, char *str2)
{
    int i;
    int HashArray[26]= {0};

    for(i=0 ; str1[i] != '\0' ; i++)
    {
        HashArray[(str1[i]-97)]++;
    }

    for(i=0 ; str2[i] != '\0' ; i++)
    {
        HashArray[(str1[i]-97)]--;

        if(HashArray[(str1[i]-97)] == -1)
        {
            printf("Not anagram\n");
            break;
        }
    }

    if(str2[i] == '\0')
    {
        printf("Anagram +____+");
    }
}



int main(void)
{
    char *s1 = (char*)malloc(255);
    char *s2 = (char*)malloc(255);
    printf("enter the string 1 : ");
    scanf("%s", s1);
    printf("enter the string 2 : ");
    scanf("%s", s2);

    printf("String 1 is - %s\n", s1);
    printf("String 2 is - %s\n", s2);

    IsAnagram(s1, s2);



    return 0;

}
