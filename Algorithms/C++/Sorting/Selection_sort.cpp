//Input -
//8
//9 7 1 4 3 2 8 5
//Output
//1 2 3 4 5 7 8 9

/*
Selection Sort is basically a comparison sorting based technique used to sort elements.
Best Case-0(n)
Worst Case-0(n^2)
Average case-0(n^2)
Space complexity-0(1)
*/

#include <iostream>

using namespace std;

void printArray(int arr[], int n);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Working of Selection Sort??
In Selection sort a min variable is selected. In every iteration min variable is updated.
The min variable is value of i in every iteration at the beginning.After that again a loop is applied whose
iteration starts with i+1. In this nested loop we compare whether any number in the array
is smaller then the element at min position arr[iMin]. And if we find any number then its position is swapped with the
element at min position. Basically the below part in the code performs this part.
   .... {
    if (arr[j] < arr[iMin])
                iMin = j;
        }
        swap(&arr[iMin], &arr[i]);
By doing this at every iteration of the ith loop we are placing the lowest element
in the array at its correct position in the ascending order.
*/
void selectionSort(int arr[], int n)
{
    int iMin;
    for (int i = 0; i < n - 2; i++)
    {
        iMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[iMin])
                iMin = j;
        }
        swap(&arr[iMin], &arr[i]);
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

    selectionSort(arr, n);

    return 0;
}
