//The below question came in amazon interview. The below question is like that
//Amazon is planing to release a new order prioritization lgo to full fill delieveries
//on time.All orders(Prime and non prime) are given an alphanumeric id code. Primeorders
//are given extra metadata in form of lowercase alphabets and non prime orders are given metadata
//in form of positive integers.

//You have to sort the list of all the orders in a way
//1. The Prime order should be returned first in lexographical order
//2. Only in the case of ties identifier should be used for backup sort
//3. The remaining non prime orders must come all after ,in the original order they were given in the input.

//Sample Input
//4 4
//mi2 jog mid pet
//wz3 34 54 398
//a1 alps cow bar
//x4 45 21 7

//Sample output

//a1 alps cow bar
//mi2 jog mid pet
//wz3 34 54 398
//x4 45 21 7

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Below function is used to sort the function on basis of column
bool sortcolumn(vector<string> v1, vector<string> v2)
{
    int i;
    for (i = 0; v1.size(); i++)
    {
        //Below condition is added for the case if both the elements are same
        //so sort will take place on the basis of next column elements.
        if (v1[i] != v2[i])
            return v1[i] < v2[i];
    }
    return v1[i] < v2[i];
}

//The below function is used to check whether in each row is there any positive number or not in case its there
//0 will be return else 1. So 1 for prime and 0 for non-prime.
int IsPrime(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 48 && a[i] <= 57)
            return 0;
    }
    return 1;
}
int main()
{
    cout << "Enter no of rows and columns";
    int r, c;
    cin >> r >> c;
    vector<vector<string> > str;

    vector<vector<string> > primeorders;
    vector<vector<string> > nonprimeorders;

    char n[100];
    int a;

    for (int i = 0; i < r; i++)
    {
        vector<string> list;

        for (int j = 0; j < c; j++)
        {
            cin >> n;
            list.push_back(n);
        }
        str.push_back(list);
        list.clear();
    }

    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 0; j < str[i].size(); j++)
        {
            cout << "\n";
            if (j)
            {
                a = IsPrime(str[i][j]);
                if (a == 0)
                    break;
            }
        }
        if (a == 1)
            primeorders.push_back(str[i]);
        else
            nonprimeorders.push_back(str[i]);
    }

    //used to sort the prime order vector
    sort(primeorders.begin(), primeorders.end(), sortcolumn);

    for (int i = 0; i < primeorders.size(); i++)
    {
        for (int j = 0; j < primeorders[i].size(); j++)
        {
            cout << primeorders[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < nonprimeorders.size(); i++)
    {
        for (int j = 0; j < nonprimeorders[i].size(); j++)
        {
            cout << nonprimeorders[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}