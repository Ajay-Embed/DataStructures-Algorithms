#include <iostream>
#include <bits/stdc++.h>

//The below code is the implementation of Two pointer algo.It is one of the most common algorithms asked in ds and algo rounds.
//In the below question we need to reverse the string in a way that the special characters remain at their position and only alphabeta are removed.
//If we use brut force the time complexity for the same would be O(n^2) but by using two pointer the time complexity can be reduced to O(n)

//The below function is used to check whether the passed character is a aphabet or not
bool isAlphabet(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main()
{

    int n;
    std::cin >> n;
    char input[] = new input[n] for (int i = 0; i < n; i++)
    {
        std::cin >> input[i];
    }
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        if (!isAlphabet(input[l]))
        {
            l++;
        }
        else if (!isAlphabet(input[r]))
        {
            r--;
        }
        else
        {
            int temp = input[l];
            input[l] = input[r];
            input[r] = temp;

            l++;
            r--;
        }
    }
    std::cout << input << std::endl;
    return 0;
}
