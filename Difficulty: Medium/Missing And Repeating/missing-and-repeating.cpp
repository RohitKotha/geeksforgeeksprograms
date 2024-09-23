//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(arr[i], maxi);
        }
        vector<int> v1(maxi + 1, 0);
        int tw, mini = INT_MAX;
        for (int i = 0; i < arr.size(); i++) {
            if (v1[arr[i]] == 0) {
                v1[arr[i]]++;
            } else if (v1[arr[i]] == 1) {
                tw = arr[i];
                v1[arr[i]]++;
            }
        }
        for (int i = 1; i < v1.size(); i++) {
            if (v1[i] == 0) {
                mini = i;
            }
        }
        if(mini==INT_MAX){
            mini=maxi+1;
        }
        return {tw, mini}; // Corrected return
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends