//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        vector<int> result;
        
        // Sort array b for efficient binary search
        sort(b.begin(), b.end());
        
        for (int i = 0; i < q; ++i) {
            int idx = query[i]; // Get the index from the query
            int value = a[idx]; // Get the corresponding value from array a
            
            // Perform binary search to find the count of elements <= value in sorted array b
            int count = upper_bound(b.begin(), b.end(), value) - b.begin();
            
            // Store the result for the current query
            result.push_back(count);
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends