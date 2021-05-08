//Input -
//8
//9 7 1 4 3 2 8 5
//Output
//1 2 3 4 5 7 8 9

//Insertion Sort is basically a shifting and insertion based technique used to sort elements.
//Best Case-0(n)
//Worst Case-0(n^2)
//Average case-0(n^2)
//Space complexity-0(1)

#include <iostream>

using namespace std;

void printArray(int arr[], int n);

void selectionSort(int arr[], int n)
{
    int value, hole;
    for (int i = 1; i < n; i++)
    {
        value = arr[i];
        hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole = hole - 1;
        }
        arr[hole] = value;
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
