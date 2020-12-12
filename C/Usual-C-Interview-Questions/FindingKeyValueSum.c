#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;               //total size of the array
    int length;             //No. of elements in the array
    int *A;                 //Pointer to array

}Array_t;

//Func prototypes
void Display(Array_t *);
void Arr_Init(Array_t *);

int main(void)
{
    Array_t arr;

    printf("Enter the size of the array\n");
    scanf("%d", &arr.size);

    //create a array of that size
    arr.A = (int *)malloc(sizeof(int)*arr.size);

    Arr_Init(&arr);
    Arr_Display(&arr);

    return 0;
}

void Arr_Display(Array_t *arr)
{
    printf("The entered array is - \n");

    for(int i=0 ; i<arr->length ; i++)
    {
        printf("%d. %d\n",i+1, arr->A[i]);
    }
}

void Arr_Init(Array_t *arr)
{
    printf("Enter the number of elements to be filled in the array\n");
    scanf("%d", &arr->length);

    printf("Fill the elements in the array\n");

    for(int i=0 ; i < arr->length ; i++)
    {
        scanf("%d", &arr->A[i]);
    }

}
