
#include <stdio.h>
#include <stdlib.h>
/*
In this program we will find duplicates in a given string
1. If a duplicate is found a flag is set which indicates that we change the duplicate element to zero so that we dont find it again.
2. After setting it to zero we simultaneously print it as well so as to confirm we are finding it.
3. If no duplicate is found we will exit the loop(s) peacefully.
4. Dont calculate the time complexity of this code. Please :(
*/

//Calculates the length of a given string
int length(char str[])
{
    int len=0;

    while(str[len] != '\0')
    {
        len++;
    }

    return len;
}


//Core logic implementation
void check_duplicate(char *str, int length)
{
    int i, j, flag;

    for(i=0 ; i<= length-2 ; i++)
    {
        //set flag to zero.
        flag = 0;

        if(str[i] != '\0')
        {
            //Here we will check for duplicates
            for(j=i+1 ; j<length-1 ; j++)
            {
                //If we find a duplicate element
                if(str[i] == str[j])
                {
                    //raise a flag
                    flag = 1;

                    //set the corresponding element to some value.
                    str[j] = 1;
                }
            }
            if(flag == 1)
            {
                printf("%c is a duplicate\n", str[i]);
            }
        }
    }

}


//Application
int main()
{
    char s[100];
    scanf("%[^\n]s", s);

    int length_of_str = length(s);
    //printf("%d", length_of_str);

    check_duplicate(s, length(s));

    return 0;
}
