// It works for DAG - Diagonal Acyclic Graph

#include <bits/stdc++.h>
using namespace std;

void TopoSortUtil(int src, vector<int> adj[], vector<int> &visited, stack<int> st) {
    visited[src] = 1;
    
    for(auto it: adj[src]) {
        if(!visited[it]) {
            TopoSortUtil(it, adj, visited, st);
        }
    }
    st.push(src);
}

vector<int> TopoSort(int V, vector<int> adj[]) {
    vector<int> visited(V+1, 0);
    stack<int> st;
    
    for(int i=0; i<=V; i++) {
        if(!visited[i]) {
            TopoSortUtil(i, adj, visited, st);
        }
    }

    // Converting stack into array
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}