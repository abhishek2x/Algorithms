// Cycle in undirected using BFS

#include<bits/stdc++.h>
using namespace std;

bool isCycleBFS(int node, vector<int> adj[], vector<int> &visited) {
    queue<pair<int, int>> q;
    q.push({node, -1});
    visited[node] = true;

    while(!q.empty()) {
        int temp = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for(auto it: adj[temp]) {
            if(!visited[it]) {
                q.push({it, temp});
                visited[it] = 1;
            }
            else if(it != parent) {
                return true;
            }
        }
    }
    return false;
}

bool checkCycle(int V, vector<int> adj[]) {
    vector<int> visited(V+1, 0);
    
    for(int i=0; i<=V; i++) {
        if(!visited[i])
            if(isCycleBFS(i, adj, visited)) 
                return true;
    }
    return false;
}