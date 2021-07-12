// Cycle in undirected using DFS

#include<bits/stdc++.h>
using namespace std;

bool isBipartiteDFS(int src, vector<int> adj[], vector<int>& color){
    color[src] = 1;

    for(auto it: adj[src]) {
        if(color[it] == -1) {
            color[it] = 1 - color[src];
            if(!isBipartiteDFS(it, adj, color)) return false;
        }   
        else if(color[it] == color[src]) return false;
    }
    return true;
}

bool checkBipartite(int V, vector<int> adj[]) {
    vector<int> color(V+1, -1);
    for(int i=0; i<=V; i++) {
        if(color[i] == -1) {
            if(!isBipartiteDFS(i, adj, color)) return false;
        }
    }
    return true;
}