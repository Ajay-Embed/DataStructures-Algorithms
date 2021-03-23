/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>

#include <list>

using namespace std;

int main()
{
    int n;
    list<int> l1;
    list<int> l2;
    list<int> l3;

    int element1, element2;
    cout << "Enter number of elemnts for list 1";
    cin >> element1;
    cout << "Enter elements";

    for (int i = 0; i < element1; i++)
    {
        cin >> n;
        l1.push_back(n);
    }

    cout << "Enter number of elemnts for list 2";
    cin >> element2;
    cout << "Enter elements";

    for (int i = 0; i < element2; i++)
    {
        cin >> n;
        l2.push_back(n);
    }

    list<int>::iterator it;
    list<int>::iterator it1;

    for (it = l1.begin(); it != l1.end(); it++)
    {
        cout << *it << " ";
    }

    for (it1 = l2.begin(); it1 != l2.end(); it1++)
    {
        cout << *it1 << " ";
    }

    return 0;
}
