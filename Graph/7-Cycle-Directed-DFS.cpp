// check cycle in directed graph using dfs
// 

#include<bits/stdc++.h>
using namespace std;


bool checkIfCycle_Util(int src, vector<int> &visited, vector<int> &BFS_visited, vector<int> adj[]) {
    visited[src] = 1;
    BFS_visited[src] = 1;

    for(auto it: adj[src]) {
        if(!visited[it]) {
            if(checkIfCycle_Util(it, visited, BFS_visited, adj)) return true;
        }
        else if(BFS_visited[it]) return true;
    }
    BFS_visited[src] = 0;
    return false;
}

bool checkIfCycle(int V, vector<int> adj[]) {
    vector<int> visited(V+1, 0);
    vector<int> BFS_visited(V+1, 0);

    for(int i=0; i<=V; i++) {
        if(!visited[i])
            checkIfCycle_Util(i, visited, BFS_visited, adj);
    }    
}

