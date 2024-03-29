// Cycle in undirected using DFS

#include<bits/stdc++.h>
using namespace std;

bool isCycleDFS(int src, int parent, vector<int> adj[], vector<int>& visited) {
	visited[src] = 1;

	for(auto it: adj[src]) {
		if(!visited[it]) {
			if(isCycleDFS(it, src, adj, visited)) return true;
		}
		else if(it != parent) return true;
	}
	return false;
}


bool checkCycle(int V, vector<int> adj[]) {
    vector<int> visited(V+1, 0);
    
    for(int i=0; i<=V; i++) {
        if(!visited[i])
            if(isCycleDFS(i, -1, adj, visited)) 
                return true;
    }
    return false;
}
