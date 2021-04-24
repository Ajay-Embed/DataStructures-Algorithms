//Sample Input

//7
//6
//1 5
//1 4
//1 2
//2 7
//2 6
//2 3

#include <iostream>
#include <list>
#include <vector>

using namespace std;
class Graph
{
public:
    int v;
    vector<int> *g;
    Graph(int x)
    {
        v = x;
        g = new vector<int>[v];
    }

    void addEdge(int s, int e)
    {
        g[s].push_back(e);
    }
    void BFS(int y)
    {

        int num;
        bool *visit = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visit[i] = false;
        }
        visit[y] = true;
        list<int> queue;
        queue.push_back(y);
        vector<int>::iterator i;
        while (!queue.empty())
        {
            num = queue.front();
            cout << num << " ";
            queue.pop_front();
            if (num != v)
            {
                for (i = g[num].begin(); i != g[num].end(); i++)
                {
                    if (!visit[*i])
                    {
                        visit[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
        }
    }
};

int main()
{
    int n, edges, s, e;
    cout << "Enter no vertices for the graph ";
    cin >> n; //7
    cout << "Enter no edges for the graph ";
    cin >> edges; //6
    Graph *g = new Graph(n);

    for (int i = 0; i < edges; i++)
    {
        cin >> s;
        cin >> e;
        g->addEdge(s, e);
    }

    g->BFS(1);
    return 0;
}
