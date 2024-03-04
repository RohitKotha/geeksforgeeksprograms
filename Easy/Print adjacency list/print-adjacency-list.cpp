//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    
    
    
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        map<int,vector<int>>mp;
        
        int max1=0;
        for(int i=0;i<edges.size();i++){
            //for(int j=0;j<edges[i].size();j++){
                mp[edges[i].first].push_back(edges[i].second);
                mp[edges[i].second].push_back(edges[i].first);
                
        }
        vector<vector<int>> v1(V, vector<int>{});
        for(auto it:mp){
            v1[it.first]=it.second;
        }
        return v1;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends