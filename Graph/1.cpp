// Checking cycle in undirected graph using BST

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {

public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited) {
        // queue<node, parent>
        queue<pair<int, int>> q;

        visited[s] = true;
        q.push({s, -1});

        while(!q.empty()) {

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it: adj[node]) {
                if(!visited[it]) {
                    visited[it] = true;
                    checkForCycle(it, V, adj, visited);
                }
                else if(it != parent) {
                    // cycle found
                    return true;
                }
            }
        }
        return false;
    }

public:
	bool isCycle(int V, vector<int>adj[]){
        vector<int> visited(V, 0);

        // Loop is used to check cycle in each component
        for(int i=0; i<V; i++) {
            if(!visited[i]) 
                if(checkForCycle(i, V, adj, visited)) return true;
        }
        return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
