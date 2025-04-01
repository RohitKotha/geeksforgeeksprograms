//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
void bfs(int row,int col, vector<vector<int>>&vis,vector<vector<char>>&grid){
      vis[row][col]=1;
      queue<pair<int,int>>q1;
      q1.push({row,col});
      int n=grid.size();
      int m=grid[0].size();
      while(!q1.empty()){
          int r=q1.front().first;
          int c=q1.front().second;
          q1.pop();
          for(int delrow=-1;delrow<=1;delrow++){
              for(int delcol=-1;delcol<=1;delcol++){
                  int nrow=r+delrow;
                  int ncol=c+delcol;
                  if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1' and !vis[nrow][ncol]){
                     vis[nrow][ncol]=1;
                      q1.push({nrow,ncol});
                     
                  }
              }
          }
      }
  }
    int numIslands(vector<vector<char>>& grid) {
          // code here
           int n=grid.size();
      int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col]&& grid[row][col] == '1'){
                 ans++;
                 bfs(row,col,vis,grid);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends