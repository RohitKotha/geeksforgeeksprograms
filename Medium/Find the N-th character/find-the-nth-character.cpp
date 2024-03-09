//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string st="";
        int ok=s.size();
        int i=0;
        while(r!=0){
            if(i<ok){
            if(s[i]=='0'){
                st+="01";
            }
            else if(s[i]=='1'){
                st+="10";
            }
            i++;
        }
        else{
            i=0;
            s=st;
            st="";
            r--;
        }
        }
            return s[n];
        }
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends