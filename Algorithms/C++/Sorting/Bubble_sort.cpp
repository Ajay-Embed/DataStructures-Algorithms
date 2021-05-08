//Input -
//8
//9 7 1 4 3 2 8 5
//Output
//1 2 3 4 5 7 8 9

//Bubble Sort is basically a comparison based technique used to sort elements.
//Best Case-0(n)(When the array is already sorted)
//Worst Case-0(n^2)
//Average case-0(n^2)
//Space complexity-0(1)
#include <iostream>

using namespace std;

void printArray(int arr[], int n);

// The below code is for swapping the elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// In Bubble sort algo we compare each pair of array element in order to get the array sorted
// in ascending or descending order.
// The below case is explained for ascending order
// 1.>The first element is taken as bubble and is compared with the adjacent element.
// 2.>In case the bubble element is greater then the adjacent then both the elements are swapped and the
// bubble goes to the adjacent element,in case if the bubble element is smaller than the adjacent then swapping
// won't take place and bubble will pass to the adjacent element.
// 3.>And then the process 2 will again take place with next 2 adjacent elemnts.

void bubbleSort(int arr[], int n, int direction)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (direction == -1)
            {
                if (arr[j] < arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
            }
            else
            {
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    printArray(arr, n);
}

//The below function is used to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int n;
    cout << "Enter no of Elements";
    cin >> n;
    int arr[n];
    cout << "Enter Values";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n, 1);
    //In bubbleSort(arr,n,1) third param is used for specifying the direction in which array should be sorted.
    //1 is for ascending order and -1 descending order
    return 0;
}
