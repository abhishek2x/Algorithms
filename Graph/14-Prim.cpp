#include<bits/stdc++.h>
using namespace std;

int N;

// <node, weight>
vector<pair<int, int>> adj[];

vector<int> parent(N, -1);
vector<int> key(N, INT_MAX);
vector<bool> mst(N, false);

// O(NlogN)
void prim_Optimised(int src) {
    
    // feat: priority queue -> Min Heap -> Min on top
    priority_queue< pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>> > pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    for(int i=0; i<N-1; i++) {

        // finding min in key array
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for(auto it: adj[u]) {
            int weight = it.second;
            int node = it.first;

            if(!mst[node] && key[node] > weight) {
                key[node] = weight;
                parent[node] = u;
                // push in priority queue
                pq.push(make_pair(key[node], node));
            }
        }
    }

    // print parent array
}

// O(N^2)
void prim_bruteforce(int src) {
    parent[0] = -1;
    key[0] = 0;

    for(int count=0; count<N-1; count++){
        
        // find min key
        int mini = INT_MAX, u=0;
        for(int i=0; i<N; i++) {
            if(!mst[i] && key[i] < mini) {
                mini = key[i];
                u = i;
            }
        }

        mst[u] = true;

        // do work
        for(auto neigh: adj[u]) {
            int weight = neigh.second;
            int node = neigh.first;

            if(!mst[node] && key[node] > weight) {
                parent[node] = u;
                key[node] = weight;
            }
        }
    }

    // parent is answer
}