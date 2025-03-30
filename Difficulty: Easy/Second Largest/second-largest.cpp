//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second largest element
    int getSecondLargest(vector<int> &arr) {
        int n1 = INT_MIN, n2 = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > n1) {
                n2 = n1;    // Update second largest before updating the largest
                n1 = arr[i];
            } else if (arr[i] != n1 && arr[i] > n2) {
                n2 = arr[i];
            }
        }
        // If no second-largest element exists
        return (n2 == INT_MIN) ? -1 : n2;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends