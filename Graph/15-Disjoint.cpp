// It's a Data Structure which maintains common parent
// of all node belonging to the same component.

// Application: Kruskal's Algorithm


#include <bits/stdc++.h>
using namespace std;

int parentArr[100000];
int rankArr[100000];

void makeSet() {
    for(int i=0; i<100000; i++) {
        parentArr[i] = i;
        rankArr[i] = 0;
    }
}

int findPar(int src) {
    if(src == parentArr[src]) return src;
    else parentArr[src] = findPar(parentArr[src]);
}

void unionn(int u, int v) {
    u = findPar(u);
    v = findPar(v);

    if(rankArr[u] < rankArr[v]) 
        parentArr[u] = v;
    else if(rankArr[v] < rankArr[u]) 
        parentArr[v] = u;
    else {
        parentArr[u] = v;
        rankArr[u]++;
    }
}

int main() {
    // Take input for values of u and v;

    // if Parent of u and v are same -> same component
}