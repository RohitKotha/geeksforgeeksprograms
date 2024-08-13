//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function
        int MOD = 1000000007;
        long long ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            ans=(ans+(long long)i*arr[i]%MOD);
        }
        return ans%MOD;
        
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
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends