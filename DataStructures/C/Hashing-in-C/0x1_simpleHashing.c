/*
    Hashing is mostly used for searching in O(1). - One to one mapping.
    This is a crude implementation of the basic idea behind hashing wherein we will print the
    repeating elements in an array using hash table.
*/

#include <stdio.h>

int main(void)
{
    int A[] = {2, 3, 6, 1, 2, 4, 6, 4, 15, 2};
    int HashTable[16] = {0};

    for(int i=0 ; i<10 ; i++)
    {
        HashTable[A[i]]++;
    }

    for(int i=0 ; i<16 ; i++)
    {
        if(HashTable[i] > 1)
        {
            printf("Element %d is present %d times \n", i, HashTable[i]);
        }
    }

    return 0;
}
