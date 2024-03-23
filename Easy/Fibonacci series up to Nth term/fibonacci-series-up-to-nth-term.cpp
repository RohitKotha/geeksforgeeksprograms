//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector<int>v1;
        v1.push_back(0);
        v1.push_back(1);
        long long int k=1e9+7;
        for(int i=2;i<=n;i++){
            int a=(v1[i-1]%k+v1[i-2]%k)%k;
            v1.push_back(a);
        }
        return v1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends