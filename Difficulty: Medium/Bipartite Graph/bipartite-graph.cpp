//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i]=-1;
        }
        queue<int>q1;
        q1.push(0);
        
        while(!q1.empty()){
            int node=q1.front();
            q1.pop();
            for(auto it:adj[node]){
                if(vis[it]==-1){
                    vis[it]=!vis[node];
                    q1.push(it);
                }else if(vis[it]==vis[node]){
                    return false;
                }
            }
            
        }
        return true;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends