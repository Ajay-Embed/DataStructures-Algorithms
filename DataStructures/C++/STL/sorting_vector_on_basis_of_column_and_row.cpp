//Below is the implementation of sorting the vector on the bassis of any particular row and column.
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

bool sortcolumn(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0]; //In index pass the columnno-1 on which you wanna sort the array.In this case we are sorting
                          //on column no 1 thatswhy 0 is passed.
}

int main()
{

    //Declarations
    std::vector<vector<int> > vect;

    int sizeofv;
    cout << " Enter size of vector";
    cin >> sizeofv;
    int n;
    vect.resize(sizeofv);

    for (int i = 0; i < sizeofv; i++)
    {
        for (int j = 0; j < sizeofv; j++)
        {
            cin >> n;
            vect[i].push_back(n);
        }
    }

    sort(vect[0].begin(), vect[0].end()); //In index pass the rowno-1 on which you wanna sort the array.In this case we are sorting
                                          //on row no 1 thatswhy 0 is passed.

    //After sorting on the basis of 1 row

    cout << "Sorting on the basis of row";
    cout << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    //After sorying on the basis of 1 column
    cout << "Sorting on the basis of column";
    cout << endl;
    sort(vect.begin(), vect.end(), sortcolumn);

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
