//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // Code here
        int n = mat.size();
        if (n == 0) return {};
        int m = mat[0].size();
        
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;
        
        vector<int> result;
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; ++i) {
                result.push_back(mat[top][i]);
            }
            top++;
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom; ++i) {
                result.push_back(mat[i][right]);
            }
            right--;
            
            // Traverse from right to left, if there are still rows remaining
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    result.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            
            // Traverse from bottom to top, if there are still columns remaining
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(mat[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends