//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int open=0,close=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }else{
                close++;
            }
            if(open==close){
                ans=max(ans,close+close);
            }else if(open<close){
                close=0;
                open=0;
            }
        }
        open=0;
        close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){
                open++;
            }else{
                close++;
            }
            if(close==open){
                ans=max(ans,close+close);
            }else if(open<close){
                close=0;
                open=0;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends