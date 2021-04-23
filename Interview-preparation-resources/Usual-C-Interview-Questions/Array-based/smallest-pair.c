/******************************************************************************

Problem statement - Given a number N <=200, construct a array of N number of elements
                    Find the smallest possible result of { A[i]+A[j]+j-i } 
                    
                    where ->  1 <= i <= j <= N
                    

*******************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


typedef struct {
    int *A;
    int size;
}Array_t;



/*
test case1 = 5,4,3,2,1
smallest pair should be A[0]+A[1]+1-0 = 1+2+1-0 = 4

test case 2 = 10,12,13,14,15,16,17
smallest pair should be A[0]+A[1]+1-0 = 10+12+1-0 = 23


*/
int smallestPair(Array_t Arr)
{
    int min = INT_MAX;
    
    int flag = 1;
    
    //Idea is simple nested for loops -brute force approach
    for(int i=0 ; i<Arr.size ; i++)
    {
        for(int j=i+1 ; j<Arr.size ; j++)
        {   
            int temp = (Arr.A[i] + Arr.A[j] + j - i);
            
            if(flag==true || temp<min)
            {
                min = temp;
                flag = false;
            }
        }
    }
    
    return min;
}



//Get the array from the user
void GetArray(Array_t *Arr)
{
    int n=0;
    printf("Enter the number of elements you want to enter in the array\n");
    scanf("%d", &n);
    
    Arr->size = n;
    
    for(int i=0 ; i<Arr->size ; i++)
    {
        printf("Enter number at array index %d - ", i);
        scanf("%d", &Arr->A[i]);
    }
    
    //Display the entered array to the user once
    printf("The array you entered is -  ");
    for(int i=0 ; i<Arr->size ; i++)
    {
        printf("%d ", Arr->A[i]);
    }
}



int main(void)
{
    Array_t Arr;
    
    GetArray(&Arr);
    
    int res = smallestPair(Arr);
    
    printf("smallest pair is - %d", res);

    return 0;
}


