// Checking cycle in undirected graph using DFS

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {

public:
    bool checkForCycle(int node, int parent, vector<int>& visited, vector<int> adj[]) {
        
        visited[node] = true;
        for(auto it: adj[node]) {
            if(!visited[it]) {
                if(checkForCycle(it, node, visited, adj)) return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }

public:
	bool isCycle(int V, vector<int>adj[]){
        vector<int> visited(V, 0);

        // Loop is used to check cycle in each component
        for(int i=0; i<V; i++) {
            if(!visited[i]) 
                if(checkForCycle(i, -1, visited, adj)) return true;
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
