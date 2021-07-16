// Printing Strongly Connected Components(SCC)

#include<bits/stdc++.h>
using namespace std;

/* STEPS: 

-> Do Topological Sort to generate a stack
-> Transpose the Graph 
-> Run DFS using stack */

void topoSort(int src, vector<int>&vis, stack<int> &st, vector<int> adj[]) {
    vis[src] = 1;

    for(auto it: adj[src]) 
        if(!vis[it])
            topoSort(it, vis, st, adj);

    st.push(src);
}

void revDFS(int src, vector<int> &vis, vector<int> transpose[]) {
    vis[src] = 1;
    cout << src << " ";
    for(auto it: transpose[src]) 
        if(!vis[it])
            revDFS(it, vis, transpose);
}

void kosaraju(int N, vector<int> adj[]) {

    // STEP 1  ->  Topo
    stack<int> st;
    vector<int> vis(N, 0);
    for(int i=0; i<N; i++) 
        if(!vis[i]) topoSort(i, vis, st, adj);

    // STEP 2  ->  Transpose
    vector<int> transpose[N];
    for(int i=0; i<N; i++) {
        vis[i] = 0;
        for(auto node: adj[i]) 
            transpose[node].push_back(i);
    }
    
    // STEP 3  ->  Printing using revDFS
    while(!st.empty()) {
        
        int node = st.top();
        st.pop();

        if(!vis[node]) {
            cout << "SCC: ";
            revDFS(node, vis, transpose);
            cout << "\n";
        }
    }
}