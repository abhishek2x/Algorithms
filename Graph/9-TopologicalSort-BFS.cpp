// Kahn's Algorithm

// We store and decrese the degree, ultimately removing the edges.

#include<bits/stdc++.h>
using namespace std;

vector<int> kahn_algo(int V, vector<int> adj[]) {
    
    vector<int> inDegree(V, 0);
    vector<int> visited(V, 0);

    for(int i=0; i<V; i++) {
        for(auto it: adj[i]) {
            inDegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<V; i++){ 
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        topo.push_back(node);
        q.pop();

        for(auto it: adj[node]) {
            inDegree[it]--;
            if(inDegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return topo;
}