//code to find all possible combinations of a given string

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void permut(string s, int i, int n)
{
    // Recursion end case
    if (i == n)
        cout << s << " ";
    else
    {
        for (int j = i; j <= n; j++)
        {

            swap(s[i], s[j]);

            permut(s, i + 1, n);

            //backtracking
            swap(s[i], s[j]);
        }
    }
}

int main()
{
    string s = "def";
    permut(s, 0, s.size() - 1);
    return 0;
}
