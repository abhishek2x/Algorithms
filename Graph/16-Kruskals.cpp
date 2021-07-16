#include<bits/stdc++.h>
using namespace std;

// First we'll implement Disjoint set

struct node {
    int u, v, wt;
    node(int f, int s, int weight) {
        u = f, v = s, wt = weight;
    }
};

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u;
    parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rankArr) {
    u = findPar(u, parent);
    v = findPar(v, parent);

    if(rankArr[u] < rankArr[v]) parent[u] = v;
    else if (rankArr[u] > rankArr[v]) parent[v] = u;
    else {
        parent[u] = v;
        rankArr[u]++;
    }
}

int comp(node a, node b) {
    return a.wt < b.wt;
}

// Kruskal works with edges
int main() {
    int N; cin >> N;
    vector<node> edges;
    // cin << u << v << wt -> edges input

    sort(edges.begin(), edges.end(), comp);
    
    vector<int> parent(N, 0);
    vector<int> rank(N);

    for(int i=0; i<N; i++) rank[i] = i;

    int cost=0;
    vector<pair<int, int>> mst;

    for(auto it: edges) {
        if(findPar(it.u, parent) != findPar(it.v, parent)) {
            cost += it.wt;
            unionn(it.u, it.v, parent, rank);
            mst.push_back(make_pair(it.u, it.v));
        }
    }

    // print mst
}