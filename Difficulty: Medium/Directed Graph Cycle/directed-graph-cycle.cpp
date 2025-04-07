//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
          vector<vector<int>>adj(V);
         for(int i=0;i<edges.size();i++){
             int u=edges[i][0];
             int v=edges[i][1];
             adj[u].push_back(v);
         }
         
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int>q1;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q1.push(i);
            }
        }
        vector<int>ans;
        while(!q1.empty()){
            int node=q1.front();
            q1.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                 if(indegree[it]==0){
                q1.push(it);
            }
            }
            
        }
        if(ans.size()==V){
            return false;
        }
        return true;
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