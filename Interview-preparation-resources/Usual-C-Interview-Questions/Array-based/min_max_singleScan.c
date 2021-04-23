
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int A[10] = {123, 700, 90, 78, 67, 900, 56, 45, 68,92};
    
    int length_of_Array = sizeof(A)/sizeof(A[0]);
    printf("the length of the array is - %d\n\n", length_of_Array);
    
    int max =  INT_MIN;
    int min =  INT_MAX;
    
    int count;
    for(count=0 ; count<length_of_Array ; count++)
    {
        if(A[count] > max)
        {
            max = A[count];
        }
        
        if(A[count] < min)
        {
            min = A[count];
        }
    }
    
    printf("The largest number in the array is %d\n", max);
    printf("The smallest number in the array is %d\n", min);

    return 0;
}
