//Below is the implementation of knapsack problem using greedy algo
//The time complexity for the same is 0(nlogn).

//Below is the sample input and output
//weight {15,25,10,20,5}
//value  {15,250,10,20,5}
//constrain total weight 25
//output- max profit that can be made is 250;

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int knapSack(int weight[], int value[], int W, int n)
{

    if (n == 0 || W == 0)
        return 0;

    if (weight[n - 1] > W)
        return knapSack(weight, value, W, n - 1);

    else
        return max((value[n - 1] + knapSack(weight, value, W - weight[n - 1], n - 1)),
                   knapSack(weight, value, W, n - 1));
}

int main()
{
    int m, W;
    cout << "Enter no of items";
    cin >> m;
    cout << "Enter Weight constrain";
    cin >> W;
    int value[m], weight[m];
    cout << "Enter Weight and their price";
    for (int i = 0; i < m; i++)
    {
        cin >> weight[i];
        cin >> value[i];
    }
    int length = sizeof(value) / sizeof(value[0]);
    cout << "Max profit that can be made is " << knapSack(weight, value, W, length);
    return 0;
}