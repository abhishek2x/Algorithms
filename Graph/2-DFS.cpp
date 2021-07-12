#include<bits/stdc++.h>
using namespace std;

void dfs_util(int src, vector<int> adj[], vector<int> &visited, vector<int> &ans) {
    visited[src] = 1;
    ans.push_back(src);

    for(auto it: adj[src]) {
        if(!visited[it]) {
            dfs_util(it, adj, visited, ans);
        }
    }
}

vector<int> dfs(int V, vector<int> adj[]) {
    vector<int> visited(V+1, 0);
    vector<int> ans;

    for(int i=0; i<=V; i++) {
        if(!visited[i]){
            dfs_util(i, adj, visited, ans);
        }
    }
    return ans;
}