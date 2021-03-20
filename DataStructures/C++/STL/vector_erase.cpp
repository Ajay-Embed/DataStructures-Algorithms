
// The first line of the input contains an integer .The next line contains  space separated
// integers(1-based index).The third line contains a single integer ,denoting the position of an
// element that should be removed from the vector.The fourth line contains two integers and  denoting the range that should be erased
// from the vector inclusive of a and exclusive of b.

// Sample Input
// 6
// 1 4 6 2 8 9
// 2
// 2 4

//Print the size of the vector in the first line and the elements of the vector
//after the two erase operations in the second line separated by space.

//Sample Output
//3
//1 8 9

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, element, start, end;
    cin >> n;
    vector<int> v;
    v.resize(n);
    for (int i = 0; i < v.size(); i++)
    {
        cin >> n;
        v[i] = n;
    }
    cin >> element;

    cin >> start;
    cin >> end;
    v.erase(v.begin() + element - 1);
    v.erase(v.begin() + start - 1, v.begin() + end - 1);
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
