//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      bool findTriplet(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i = 2; i < n; i++) {
            int st = 0, end = i-1;
            int target = arr[i];
            while(st < end) {
                if(arr[st] + arr[end] == target) return true;
                else if(arr[st] + arr[end] < target) st++;
                else end--;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends