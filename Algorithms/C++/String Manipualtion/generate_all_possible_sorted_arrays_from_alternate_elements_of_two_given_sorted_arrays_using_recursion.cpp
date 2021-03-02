
// Given two sorted arrays A and B, generate all possible arrays such that first element is taken from A then
// from B then from A and so on in increasing order till the arrays exhausted.
// The generated arrays should end with an element from B.

// for Eg

// A = {10, 15, 25}
// B = {1, 5, 20, 30}

// The resulting arrays are:
//   10 20
//   10 20 25 30
//   10 30
//   15 20
//   15 20 25 30
//   15 30
//   25 30

//The below question was asked in Google interview round. The below code is implemented using recurssion.

//1. If flag is true take elements from A and if flag is false take elements from B.
#include <iostream>
using namespace std;

void printArr(int a[], int n);
void generateSubArray(int a[], int b[], int c[], int i, int j, int m, int n, int len, int flag)
{
    if (flag) //Include elemnt from A
    {
        if (len) // The below check is used to trigger the print Arr function once we have inserted value from array B into C
            printArr(c, len);
        for (int k = i; k < m; k++)
        {
            if (!len) // The below check is used to include first element.
            {
                c[len] = a[k];
                generateSubArray(a, b, c, k + 1, j, m, n, len, !flag);
            }
            else
            {
                if (a[k] > c[len])
                {
                    c[len + 1] = a[k];
                    generateSubArray(a, b, c, k + 1, j, m, n, len + 1, !flag); //recursive function
                }
            }
        }
    }
    else //Include element from B
    {
        for (int l = j; l < n; l++)
        {

            if (b[l] > c[len])
            {
                c[len + 1] = b[l];
                generateSubArray(a, b, c, i, j + 1, m, n, len + 1, !flag); //recursive function
            }
        }
    }
}
void generate(int a[], int b[], int m, int n)
{
    int c[m + n];
    generateSubArray(a, b, c, 0, 0, m, n, 0, true);
}

//The below function is used to print array c
void printArr(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int m, n;
    cout << "enter m and n values"; // m and n will be size of array a and array b
    cin >> m;
    cin >> n;
    int a[m];
    int b[n];
    cout << "enter array 1"
         << " ";
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    cout << "enter array 2"
         << " ";

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    generate(a, b, m, n);
    return 0;
}
