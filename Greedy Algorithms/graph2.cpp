/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

// City traversal

#include <bits/stdc++.h>
using namespace std;

// We are using template to make it Generic in Nature
template <typename T>
class Graph
{

    map<T, list<T>> adjList;

public:
    Graph()
    {
        // A constructor is important
    }

    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        // To iterate over a map we use for each loop
        for (auto row : adjList)
        {
            T key = row.first;
            cout << key << "= > ";
            for (T element : row.second)
            {
                cout << element << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph<string> g;

    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Siachen");
    g.addEdge("Delhi", "Banglore");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Amritsar", "Siachen");

    g.printAdjList();

    return 0;
}