//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool solve(int i,int j, vector<vector<char>>& mat, string& word,int tra, vector<vector<bool>> &brok){
      if(tra>=word.size()){
          return true;
      }
      if(i<0 or j<0 or i>=mat.size() or j>=mat[0].size() or brok[i][j] or mat[i][j]!=word[tra]){
          return false;
      }
      brok[i][j]=true;
      if(solve(i,j+1,mat,word,tra+1,brok) or solve(i,j-1,mat,word,tra+1,brok) or solve(i+1,j,mat,word,tra+1,brok) or solve(i-1,j,mat,word,tra+1,brok)){ 
          return true;
      }
      brok[i][j]=false;
      return false;
  }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>> brok(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                if(solve(i,j,mat,word,0,brok)){
                    return true;
                }
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
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
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