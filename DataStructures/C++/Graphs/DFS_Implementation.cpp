//Sample Input

//10
//7
//0 1
//0 9
//1 2
//2 0
//2 3
//9 3

// Sample output
// 1 2 0 9 3
#include <iostream>
#include <list>
#include <vector>

using namespace std;
class Graph
{
public:
    int v;
    vector<int> *g;
    bool *visit = new bool[v];

    Graph(int x)
    {
        v = x;
        g = new vector<int>[v];
    }

    void addEdge(int s, int e)

    {
        cout << "hello ";
        g[s].push_back(e);
    }
    void DFS(int y)
    {

        // int num;

        visit[y] = true;
        //list<int> queue;
        //queue.push_back(y);
        vector<int>::iterator i;

        cout << y << " ";
        //queue.pop_front();

        for (i = g[y].begin(); i != g[y].end(); i++)
        {
            if (!visit[*i])
            {
                DFS(*i);
            }
        }
    }
};

int main()
{
    int n, edges, s, e;
    cout << "Enter no vertices for the graph ";
    cin >> n; //10
    cout << "Enter no edges for the graph ";
    cin >> edges; //6
    Graph *g = new Graph(n);

    for (int i = 0; i < edges; i++)
    {
        cin >> s;
        cin >> e;
        g->addEdge(s, e);
    }

    g->DFS(1);
    return 0;
}
