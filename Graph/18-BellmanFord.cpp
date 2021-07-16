// Used to find shortest path in a graph containing "negative" weights.

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int u, v, w;
    Node(int s, int f, int wt) {
        u = s, v = f, w = wt;
    }
};

int Bellman(int N, vector<Node> edges) {
    vector<int> weight(N, INT_MAX);
    weight[0] = 0;

    // Iterate for N-1 times
    for(int i=0; i<N-1; i++) 
        for(auto it: edges)
            if(weight[it.u] + it.w < weight[it.v]) 
                weight[it.v] = weight[it.u] + it.w;

    // Nth traversal to detech -ve cycle
    int flag = 0;
    for(auto it: edges) 
        if(weight[it.u] + it.w < weight[it.v]) {
            flag = 1;
            cout << "Negative cycle detected";
            break;
        }
    
    if(flag == 0) {
        // print weight[]
    }
}

