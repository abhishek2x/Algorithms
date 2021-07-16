// Shortest path in a DAG

#include <bits/stdc++.h>
using namespace std;

// vector<pair<{value}, {weight}>> adj[]

void topoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        topoSort(it.first, vis, st, adj);
    }
    st.push(node);
}

void ShortestPath(int N, vector<pair<int, int>> adj[]) {

    // get topoSort Stack
    vector<int>vis(N, 0);
    stack<int> st;

    for(int i=0; i<N; i++)
        if(!vis[i]) 
            topoSort(i, vis, st, adj);

    // perform bfs on that
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    while(st.empty()) {
        int node = st.top();
        st.pop();

        if(dist[node] != INT_MAX) 
            for(auto it: adj[node]) 
                if(dist[node] + it.second < dist[it.first])
                    dist[it.first] = dist[node] + it.second;
    }

    // print dist array
}