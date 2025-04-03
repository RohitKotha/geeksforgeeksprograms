//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// in dfs
class Solution {
  public:
  void dfs(int sr,int sc, vector<vector<int>>& ans,vector<vector<int>>& image, int newColor, int delrow[], int delcol[],int inicolor){
      ans[sr][sc]=newColor;
      int n=image.size();
      int m=image[0].size();
      for(int i=0;i<4;i++){
          int nr=sr+delrow[i];
          int nc=sc+delcol[i];
          if(nr>=0 and nr<n and nc>=0 and nc<m and image[nr][nc]==inicolor and ans[nr][nc]!=newColor){
               dfs(nr,nc,ans,image,newColor,delrow,delcol,inicolor);
          }
      }
  }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        
        int inicolor=image[sr][sc];
        vector<vector<int>>ans =image;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(sr,sc,ans,image,newColor,delrow,delcol,inicolor);
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
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends