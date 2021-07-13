// Shortest path in undirected graph with unit weight

#include <bits/stdc++.h>
using namespace std;

vector<int> getDist(int V, vector<int> adj[]) {
    
    vector<int> dist(V, INT_MAX);
    queue<int> q;

    q.push(0);
    dist[0] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it: adj[node]) {
            if(dist[node] + 1 < dist[it]) 
                dist[it] = dist[node]+1;
                q.push(it);
        }
    }
    return dist;
}
