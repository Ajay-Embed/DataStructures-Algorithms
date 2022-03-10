#include <stdio.h>


void merge(int arr[], int l, int m, int h)
{
    int n = m-l+1; // low to mid
    int r = h-m; // mid+1 to high
    int left[n]; int right[r]; ;

    for(int i=0; i<n; i++)
    {
        left[i] = arr[i+l];
    }

    for(int i=0; i<r; i++)
    {
        right[i] = arr[m+1+i]; 
    }

    int i =0, j=0, k=l; 

    while(i<n && j<r)
    {
        if(left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }

        else
        {
            arr[k++] = right[j++]; 
        }
    }
    
    /* Fill if elements were remaining in one array */
    while(i<n)
        arr[k++] = left[i++];
    
    while(j<r)
        arr[k++] = right[j++];
}

void mergesort(int arr[], int l, int h)
{
    if(l<h)
    {
        int mid = ((h+l)/2);
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}


int main()
{
    int arr1[] = {2, 3, 1, 8, 4, 6, 7, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    mergesort(arr1, 0, n1-1);

    for (int i=0; i < n1; i++)
        printf("%d ", arr1[i]);
 
    return 0;
}
