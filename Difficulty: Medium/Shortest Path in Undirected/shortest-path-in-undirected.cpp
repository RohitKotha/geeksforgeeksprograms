//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        //int dis[adj.size()]={0};
        int n=adj.size();
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        queue<int>q1;
        q1.push(src);
        
        while(!q1.empty()){
            
            int node=q1.front();
            q1.pop();
            for(auto it:adj[node]){
                if(dis[node]+1<dis[it]){
                    dis[it]=1+dis[node];
                    q1.push(it);
                }
            }
        }
     
     for(int i = 0; i < n; i++) {
            if(dis[i] == INT_MAX) {
                dis[i] = -1;
            }
        }
     return dis;   
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends