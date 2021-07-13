// check cycle in directed graph using bfs
// We'll use reverse apprach, i.e using Kahn to prove it's acyclic

#include<bits/stdc++.h>
using namespace std;


bool is_not_cyclic(int V, vector<int> adj[]) {
    
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

    int cnt=0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it: adj[node]) {
            inDegree[it]--;
            if(inDegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return cnt == V;
}