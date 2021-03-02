
//The below code is the implementation of Two pointer algo.It is one of the most common algorithms asked in ds and algo rounds.
//In the below question we need to find whether there is a triplet in the array or not. If the array would have any three elements which would have sum as zero then we
//can refer the array as triplet else not.
//If we use brut force the time complexity for the same would be O(n^3) but by using two pointer the time complexity can be reduced to O(n^2)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sumofnum(int a[], int x, int i, int n);

bool triplets(int a[], int n)
{
    sort(a, a + n);

    for (int i = 0; i < n - 2; i++)
    {
        if (sumofnum(a, -a[i], i + 1, n))
        {
            return true;
        }
    }
    return false;
}
//In this function we will find whether sum of any two number in array is equal to the opposite value of x or not
bool sumofnum(int a[], int x, int i, int n)
{
    int j = n - 1;
    ;
    while (i < j)
    {
        if (a[i] + a[j] > x)
            j--;
        else if (a[i] + a[j] < x)
            i++;
        else
            return true;
    }
    return false;
}

int main()
{
    //no of elements in array
    int n;
    cin >> n;
    int arr[] = new int[n]
        //values of elemnts in array
        for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << triplets(arr, n);

    return 0;
}