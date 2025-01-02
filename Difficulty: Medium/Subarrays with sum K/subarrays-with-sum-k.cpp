//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &nums, int k) {
        // code here
        unordered_map<int,int>mp;
        int pre=0;
        mp[0]=1;
        int rem;
        int c=0;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            rem=pre-k;
            if(mp.find(rem)!=mp.end()){
                c+=mp[rem];
            }
            mp[pre]++;

        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends