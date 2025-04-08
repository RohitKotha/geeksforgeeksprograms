//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
public:
    void ts(int node, int vis[], vector<pair<int,int>> adj[], stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            int v = it.first;
            if(!vis[v]) {
                ts(v, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[V];
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        
        int vis[V] = {0};
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                ts(i, vis, adj, st);
            }
        }
        
        vector<int> dis(V, INT_MAX);
        dis[0] = 0; // source node
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            // Only process nodes that are reachable from source
            if(dis[node] != INT_MAX) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int w = it.second;
                    if(dis[node] + w < dis[v]) {
                        dis[v] = dis[node] + w;
                    }
                }
            }
        }
        
        // Replace INT_MAX with -1 for unreachable nodes
        for(int i = 0; i < V; i++) {
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends