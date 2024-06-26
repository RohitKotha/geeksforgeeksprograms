//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  bool isvalid(vector<vector<int>>& matrix,int i,int j){
      return i>=0 and i< matrix.size() and j>=0 and j<matrix[0].size() and matrix[i][j]==1;
      
  }
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int c=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    if(isvalid(matrix,i-1,j)) c++;
                    if(isvalid(matrix,i+1,j)) c++;
                    if(isvalid(matrix,i,j-1))c++;
                    if(isvalid(matrix,i,j+1))c++;
                }
            }
        }
        return c;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends