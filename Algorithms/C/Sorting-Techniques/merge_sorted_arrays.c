#include <stdio.h>


void mergeArrays(int arr1[], int arr2[], int n, int m, int arr[])
{
    int i=0; 
    int j=0; 
    int k=0;

    while(i<n && j<m)
    {
        if(arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++]; 
        }

        else
        {
            arr[k++] = arr2[j++];
        }
    }

    while(i<n)
    {
        arr[k++] = arr1[i++];
    }

    while(j<m)
    {
        arr[k++] = arr2[j++];
    }
}


int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    int arr3[n1+n2];
    mergeArrays(arr1, arr2, n1, n2, arr3);

    for (int i=0; i < n1+n2; i++)
        printf("%d ", arr3[i]);
 
    return 0;
}
