//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            if(mat[i][0]<=x and mat[i][m-1]>=x){
                int l=0,r=m-1;
                int mid=(l+r)/2;
                while(l<=r){
                    if(mat[i][mid]==x){
                        return true;
                    }
                    if(mat[i][mid]>x){
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                    mid=(l+r)/2;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends