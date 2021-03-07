
//The below code is implementation of making adjacency list using vectors. To create adjacency list for
//given tree structure.

//no of edges 8
//srcnode destinationnode
//1 3
//2 4
//2 5
//3 6
//3 8
//1 2

//output
//2 3
//4 5
//6 8

//Adjacency list
//at 1 node connecting nodes are----2 3
//at 2 node connecting nodes are----4 5
//at 3 node connecting nodes are----6 8

//So now we can see that a 2d vector will be made which will be like
//0---
//1---2 3
//2---4 5
//3---6 8
//4---
//5---
//6---
//7---
//8---
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{

    //Declarations
    std::vector<vector<int> > Tree;
    int edge, srcnode, destinationnode;

    cout << "Enter no of Edges ";
    cin >> edge;

    Tree.resize(edge);

    cout << "Enter source and destination node";
    for (int i = 0; i < edge; i++)
    {
        cin >> srcnode >> destinationnode;
        Tree[srcnode].push_back(destinationnode);
    }

    for (int i = 0; i < Tree.size(); i++)
    {
        for (int j = 0; j < Tree[i].size(); j++)
        {
            cout << Tree[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
