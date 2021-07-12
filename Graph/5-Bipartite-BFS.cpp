// Cycle in undirected using BFS

#include<bits/stdc++.h>
using namespace std;

bool isBipartiteBFS(int src, vector<int> adj[], vector<int>& color){
    color[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it: adj[node]) {
            if(color[it] == -1          ) {
                color[it] = 1-color[node];
                q.push(it);
            }
            else if(color[it] == color[node]) return false;
        }
    }
    return true;
}

bool checkBipartite(int V, vector<int> adj[]) {
    vector<int> color(V+1, -1);
    for(int i=0; i<=V; i++) {
        if(color[i] == -1) {
            if(!isBipartiteBFS(i, adj, color)) return false;
        }
    }
    return true;
}