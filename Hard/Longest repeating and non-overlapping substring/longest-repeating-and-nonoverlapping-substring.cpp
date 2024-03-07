//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        vector<vector<int>> v(n+1,vector<int>(n+1,0));
        int maxlen=0,last=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(s[i-1]==s[j-1] and v[i-1][j-1]<(j-i)){
                    v[i][j]=v[i-1][j-1]+1;
                    if(maxlen<v[i][j]){
                        maxlen=v[i][j];
                        last=i-1;
                    }
                }
            }
        }
        return maxlen==0?"-1":s.substr(last-maxlen+1,maxlen);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends