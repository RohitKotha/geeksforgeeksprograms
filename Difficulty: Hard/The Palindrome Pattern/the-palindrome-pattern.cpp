//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool ispalin(vector<int>arr,int n){
        
        for(int i=0;i<n;i++){
           if(arr[i]!= arr[n-1-i]){
               return false;
           }
       }
       return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size();
        
        for(int i=0;i<arr.size();i++){
            vector<int> v1;
            for(int j=0;j<arr[0].size();j++){
                v1.push_back(arr[i][j]);
            }
            if(ispalin(v1,v1.size())){
                string st=to_string(i);
                st+=" R";
                return st;
            }
        }
         for(int i = 0; i < n; i++) {
            vector<int> v1;
            for(int j = 0; j < n; j++) {
                v1.push_back(arr[j][i]);
            }
            if(ispalin(v1, v1.size())) {
                return to_string(i) + " C";
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends