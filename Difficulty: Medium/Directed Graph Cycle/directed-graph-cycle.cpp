//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool dfs(int i, int n, vector<vector<int>>& adj, int path[], int vis[]) {
        vis[i] = 1;
        path[i] = 1;
        for (auto it : adj[i]) {
            if (!vis[it]) {
                if (dfs(it, n, adj, path, vis)) {
                    return true;
                }
            } else if (path[it]) {
                return true;
            }
        }
        path[i] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<vector<int>> adjok(V);
        for(int i=0;i<adj.size();i++){
            int u=adj[i][0];
            int v=adj[i][1];
            adjok[u].push_back(v);
        }
        int vis[V] = {0};
        int path[V] = {0};
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, V, adjok, path, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends