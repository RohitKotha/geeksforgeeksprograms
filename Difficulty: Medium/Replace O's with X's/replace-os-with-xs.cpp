//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  void dfs(int i,int j,vector<vector<char>>& vis,vector<vector<char>>&mat){
      vis[i][j]=1;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
      for(int it=0;it<4;it++){
          int ni=i+drow[it];
          int nj=j+dcol[it];
          if(ni>=0 and ni<mat.size() and nj>=0 and nj<mat[0].size() and !vis[ni][nj] and mat[ni][nj]=='O'){
              //vis[node]=1;
              dfs(ni,nj,vis,mat);
          }
      }
  }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        vector<vector<char>>vis(n,vector<char>(m,0));
        for(int j=0;j<m;j++){
           if(!vis[0][j] and mat[0][j]=='O'){
               dfs(0,j,vis,mat);
           }
           if(!vis[n-1][j] and mat[n-1][j]=='O'){
              dfs(n-1,j,vis,mat);
           }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] and mat[i][0]=='O'){
                dfs(i,0,vis,mat);
            }
            if(!vis[i][m-1] and mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
         return mat;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends