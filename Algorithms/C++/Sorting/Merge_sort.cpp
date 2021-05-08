//Input -
//8
//9 7 1 4 3 2 8 5
//Output
//1 2 3 4 5 7 8 9

//The time complexity of merge sort is O(n*Log n) in all the 3 cases (worst, average and best).

//Why complexity is O(n*Log n)????

//In merge sort we keep on dividing the array in two halves until the size of array
//becomes 1.So let's take the case of above example.

//How many time we will divide an array of 8 elments by 2 so it becomes 1.
//It's 3. The formula is something like this N/2^x=1 or N=2^x,where N is 8(no of elements)
//so if we apply log on both sides then x=LogN.Now as we are doing 3 passes as
//we have got value of x as 3 which stands for number of passes,
//so at each pass n elements are involved so we will multiply x by n,which gives
//my time complexity as O(nLog n)
#include <iostream>

using namespace std;

//variable l stands for the lowest position of the array,h stands for the
//highest position of the array and mid stands fot the middle element of the array.

//The below function is used to merge the two arrays ar1 and ar2
void merge(int arr[], int l, int mid, int h)
{

    int lenarr1 = mid - l + 1;
    int lenarr2 = h - mid;

    int ar1[lenarr1], ar2[lenarr2];
    for (int i = 0; i < lenarr1; i++)
        ar1[i] = arr[l + i];
    for (int j = 0; j < lenarr2; j++)
        ar2[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < lenarr1 && j < lenarr2)
    {
        if (ar1[i] < ar2[j])
            arr[k++] = ar1[i++];

        else
            arr[k++] = ar2[j++];
    }

    for (; i < lenarr1; i++)
        arr[k++] = ar1[i];

    for (; j < lenarr2; j++)
        arr[k++] = ar2[j];
}
void mergeSort(int arr[], int l, int h)
{
    //You can uncomment thi below line and check sequence of recursive function
    //cout <<"merge sort "<<"l "<<l<<" h "<<h<<"\n";

    if (l < h)
    {
        //we divide the array in two parts with mid as last index of 1 array
        //and mid+1 as starting index of 2 array
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);     // this call is for first half of the array
        mergeSort(arr, mid + 1, h); //// this call is for second half of the array
        merge(arr, l, mid, h);
    }
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
    cout << "Enter no of elements";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
