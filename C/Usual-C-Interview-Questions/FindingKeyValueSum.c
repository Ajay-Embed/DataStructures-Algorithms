#include <stdio.h>
#include <stdlib.h>


//MACROS
#define SIZE 10


//Prototypes
int LargestElement(int A[], int size);
void SumKey_HashTable(int A[], int key);

//Finding a pair of elements in an array which adds up to a certain given key value
//The array has no duplicate elements, even if it has, remove them and then perform operation


//Application Entry
int main(void)
{
    int A[SIZE] = {7,3,4,6,5,2,6,100,1,8};
    SumKey_HashTable(A, SIZE);

return 0;
}


//Marking the Hash array
void SumKey_HashTable(int A[], int key)
{
    int Max = LargestElement(A, SIZE);

    //To do in O(N) --- > Create a hash array
    int *H = (int *)malloc(sizeof(int)*Max);

    for(int i = 0 ; i<SIZE ; i++)
    {
        if(H[key-A[i]] != 0)
        {
            printf("%d + %d = %d\n", A[i], key-A[i], key);
        }
        H[A[i]]++;                  //Increment the hash array index value from 0 --> 1
    }
}

//TO find the largest elemnt in the array to create the Hash array accordingly
int LargestElement(int A[], int size)
{
    int i=0;
    int max = 0;

    for(i=0 ; i<size ; ++i)
    {
        if(max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

