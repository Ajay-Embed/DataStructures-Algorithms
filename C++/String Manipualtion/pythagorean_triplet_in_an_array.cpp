
//The below code is the implementation of Three pointer algo.It is one of the most common algorithms asked in ds and algo rounds.
//In the below question we need to find whether there is a triplet in the array which follows the pythagoras rule or not.
//If the array would have any three elements which would follow the pythagoras rule then we will consider it as pythagoras triplet.
//If we use brut force the time complexity for the same would be O(n^3) but by using three pointer the time complexity can be reduced to O(n^2)

// Input:a[]= {6, 5, 4, 9, 3}
// Output: Triplets are 3 4 5

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool sum(int a[], int c[], int x, int k, int n);
void printArr(int c[]);

bool pythagorasTriplets(int a[], int c[], int n)
{
    int len = 0;
    int count = 0;
    sort(a, a + n);
    for (int i = n - 1; i >= 2; i--)
    {
        if (sum(a, c, a[i] * a[i], i - 1, n))
        {
            c[0] = a[i];
            printArr(c);
            count = 1;
            break;
        }
    }
    if (count == 0)
    {
        cout << "No Triplets found for pythagoras theorem";
    }
}

void printArr(int c[])
{
    cout << "Triplets are " << c[2] << " " << c[1] << " " << c[0];
}

//The below function is used to check whether any two numbers square addition is equal to the number x.
bool sum(int a[], int c[], int x, int k, int n)
{
    int j = 0;
    while (j < k)
    {
        if ((a[k] * a[k]) + (a[j] * a[j]) > x)
            k--;

        else if ((a[k] * a[k]) + (a[j] * a[j]) < x)
            j++;

        else if ((a[k] * a[k]) + (a[j] * a[j]) == x)

        {
            c[1] = a[k];
            c[2] = a[j];
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "Enter length of array ";
    int n;
    cin >> n;
    int a[n];
    cout << "enter values for array ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int c[3];
    pythagorasTriplets(a, c, 5);
    return 0;
}
