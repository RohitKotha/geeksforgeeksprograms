//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
         int n=grid.size();
        int m=grid[0].size();
        queue< pair<pair<int,int>, int> >q1;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]==2;
                    q1.push({{i,j},0});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int tm=0;
        int cf=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};

        while(!q1.empty()){
            int r=q1.front().first.first;
            int c=q1.front().first.second;
            int t=q1.front().second;
            tm=max(t,tm);
            q1.pop();

            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and vis[nr][nc]==0 and grid[nr][nc]==1){
                    q1.push({{nr,nc},t+1});
                    vis[nr][nc]=2;
                    cf++;
                }
            }

        }
        return  ( (cf==fresh) ? tm:-1 );
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends