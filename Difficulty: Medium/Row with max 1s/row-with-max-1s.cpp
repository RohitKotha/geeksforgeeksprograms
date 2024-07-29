//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        
        int maxi=-1;
        int n=arr.size(),m=arr[0].size()-1;
        for(int i=0;i<n;i++){
            
            if(arr[i][0]==1){
                return i;
                break;
            }else{
                while(m>=0 and arr[i][m]==1){
                    m--;
                    maxi=i;
                }
            }
            
            
            
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends