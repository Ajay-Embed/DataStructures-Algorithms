//Input -
//8
//9 7 1 4 3 2 8 5
//Output
//1 2 3 4 5 7 8 9

//The Quick sort algo uses the concept of divide and conquer
//The time complexity of quick sort for below mentioned 3 cases are
//Best Case-0(n*logn)
//Worst Case-0(n^2)
//Average case-0(n*logn)

#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void swap(int *, int *);

/*
1. After selecting an element as pivot, which is the first index of the array in our case, 
we divide the array for the first time.
2. In Quick sort this process is called partition where elements are positioned in such a way that
elements smaller than the pivot will be on left side and elements greater than the pivot will be on right side. 
3. The pivot element will be at its sorted position. After that we will again perform partition for the elements 
on left and right side of pivot by dividing them into subarrays.
*/
int partition(int arr[], int l, int h)
{
    //variable l stands for the starting position of the array,h stands for the
    //ending position of the array

    int pivot = arr[l];
    int i = l, j = h;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[l], &arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h)
{

    if (l < h)
    {
        int p = partition(arr, l, h);
        quickSort(arr, l, p);
        quickSort(arr, p + 1, h);
    }
}

// The below code is for swapping the elements
void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

//The below function is used to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{

    int n;
    cout << "Enter no of elements";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
