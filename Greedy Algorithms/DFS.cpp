/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{

    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    // Recirsive method
    void dfs_helper(T src, map<T, bool> &visited)
    {

        cout << src << " ";
        visited[src] = true;

        for (T nbs : l[src])
        {
            if (!visited[nbs])
            {
                dfs_helper(nbs, visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T, bool> visited;

        // This loop is just for initialization
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }

        dfs_helper(src, visited);
    }
};

int main()
{

    ios ::sync_with_stdio(false);
    cin.tie(0);

    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 0);

    g.dfs(0);

    return 0;
}