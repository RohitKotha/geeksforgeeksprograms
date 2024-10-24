//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        vector<int>ans(arr.size(),0);
        int j=0;
        for(int i=0;i<arr.size()-1;i++){
            
            if(arr[i]!=0 and arr[i]==arr[i+1]){
                arr[i]*=2;
                arr[i+1]=0;
            }
            if(arr[i]!=0){
                ans[j]=(arr[i]);
                j++;
            }
        }
        if(arr[arr.size()-1]!=0){
            ans[j]=(arr[arr.size()-1]);
        }
        return ans;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends