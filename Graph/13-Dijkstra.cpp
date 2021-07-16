#include <bits/stdc++.h>
using namespace std;


void dijkstra(int src, int N, vector<pair<int, int>> adj[]) {

    set<pair<int, int>> st;
    vector<int> dist(N, 0);
    
    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()){
        auto p = *(st.begin());
        int nodeDist = p.first;
        int data = p.second;
        st.erase(st.begin());
        
        // adj->second = distance
        // adj->first = node

        for(auto it: adj[data]) {
            if(nodeDist + it.second < dist[it.first]) {
                auto f = st.find(make_pair(dist[it.first], it.first));
                if(f != st.end()) st.erase(f);

                dist[it.first] = nodeDist + it.second;
                st.insert(make_pair(dist[it.first], it.first));
            }
        }
    }

    // print dist[]
}