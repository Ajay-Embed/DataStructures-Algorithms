#include <iostream>
#include <bits/stdc++.h>

bool isAlphabet(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main()
{
    char input[] = "a$bc";
    int l = 0;
    int r = 3;

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
