#include<bits/stdc++.h>
using namespace std;

void bfs_util(int src, vector<int> adj[], vector<int> &visited, vector<int> ans) {
    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while(!q.empty()) {
        
        int node = q.front();
        q.pop();
        ans.push_back(src);

        for(auto it: adj[node]) {
            if(!visited[src]){
                q.push(node);
                visited[node] = 1;
            }
        }
    }
}

vector<int> bfs(int V, vector<int> adj[]) {
    
    vector<int> visited(V+1, 0);
    vector<int> ans;

    for(int i=0; i<=V; i++)
        if(!visited[i])
            bfs_util(i, adj, visited, ans);

    return ans;
}