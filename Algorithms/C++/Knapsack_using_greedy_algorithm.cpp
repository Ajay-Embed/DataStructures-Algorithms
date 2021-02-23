//Below is the implementation of knapsack problem using greedy algo
//The time complexity for the same is 0(nlogn).

//Below is the sample input and output
//weight {2,3,5,7,1,4,1}
//profit {10,5,15,7,6,18,3}
//constrain total weight 15
//output- max profit on weight 15 is 55.33;

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    double w;
    double p;
    double pbw;
} ppw;

bool cmp(ppw a, ppw b)
{
    return a.pbw > b.pbw;
}
void knapsack(ppw ppw[], double totalweight, int n)
{
    double count = 0;
    double totalprofit = 0;
    for (int i = 0; i < n; i++)
    {
        ppw[i].pbw = ppw[i].p / ppw[i].w;
    }
    sort(ppw, ppw + n, cmp);

    for (int i = 0; i < n; i++)
    {
        count = count + ppw[i].w;

        if (count < totalweight)
        {
            totalprofit = totalprofit + ppw[i].p;
        }

        else
        {
            count = count - ppw[i].w;
            double wt = totalweight - count;
            totalprofit = totalprofit + (ppw[i].pbw * wt);
            count = count + wt;
            break;
        }
    }
    cout << "max profit on weight " << count << " is " << totalprofit;
}
int main()
{
    int n, k;
    cout << "enter number of items ";
    cin >> n;
    ppw ppw[n];
    cout << "Enter weight of items ";
    for (int i = 0; i < n; i++)
    {
        cin >> ppw[i].w;
    }
    cout << "Enter profit of items ";

    for (int i = 0; i < n; i++)
    {
        cin >> ppw[i].p;
    }

    cout << "Enter value of knapsack ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        profitperweight[i] = profitarray[i] / weightarray[i];
    }

    knapsack(ppw, k, n);
    return 0;
}
