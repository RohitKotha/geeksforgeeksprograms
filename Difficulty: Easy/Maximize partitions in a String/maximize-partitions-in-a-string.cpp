//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n=s.size();
        int ans=0;
        vector<int>mp(26,-1);
        for(int i=0;i<n;i++){
            mp[(s[i]-'a')]=i;
        }
        int i=0;
        while(i<n){
            int end=mp[(s[i]-'a')];
            int j=i;
            while(j<end){
                end=max(end,mp[s[j]-'a']);
                j++;
            }
            ans++;
            i=j+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends