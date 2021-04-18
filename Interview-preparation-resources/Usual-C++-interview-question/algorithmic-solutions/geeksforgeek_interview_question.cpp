//Note:Indexing starts from 1
//Input1 :an intger n denoating the length of array
//Input2 :an integer m
//Input3 :amount of n number of cookies

//Output: Return the minimum amount ,a person needs to spend in order to buy at least m cookies.

// A packet of type i has 2^i-1 number of cookies
//Sample Input
//Input1:4
//Input2:12
//Input3:{20,30,70,90}

//Sample Output
//150

//There are multiple ways that person can buy 12 cookies.The optimal way for him
//is to buy a type 4 packet for rs 90 and then buy type 2 packet for rs 30.Then the person will get
//12 cookies for rs150

//Sample Input
//Input1:4
//Input2:3
//Input3:{1000,1000,100,10}

//Sample Output
//10

//The person needs only 3 cookies.The best way for him is to buy a single
//packet of type 4 for rs 10 as it has 8 cookies

//The below question can be solved using knapsack approach.
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct
{
    float amount;
    float quantity;
    float abq; //amount/quantity
} cookies;

bool cmp(cookies a, cookies b)
{
    return a.abq < b.abq;
}
int main()
{
    cout << "Enter number of types cookies";
    int n, m, totalprice = 0, count = 0, dummyprice = 0;
    cin >> n;
    cout << "Enter constraint";
    cin >> m;
    cout << "Enter amount of cookies";
    cookies cookies[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cookies[i].amount;
    }

    for (int i = 0; i < n; i++)
    {
        cookies[i].quantity = pow(2, i + 1 - 1);
    }

    for (int i = 0; i < n; i++)
    {
        cookies[i].abq = cookies[i].amount / cookies[i].quantity;
    }

    std::sort(cookies, cookies + n, cmp);

    for (int i = 0; i < n; i++)
    {
        count = count + cookies[i].quantity;
        if (count < m)
        {
            totalprice = totalprice + cookies[i].amount;
        }
        else
        {
            if (i != 0)
            {
                count = count - cookies[i].quantity;
                float wt = m - count;
                dummyprice = totalprice;
                totalprice = totalprice + (cookies[i].abq) * wt;
                dummyprice = dummyprice + (cookies[i - 1].abq) * wt;
                if (dummyprice < totalprice)
                {
                    totalprice = dummyprice;
                }
                break;
            }
            else
            {
                totalprice = cookies[i].amount;
                break;
            }
        }
    }
    cout << "min price is " << totalprice;
}
