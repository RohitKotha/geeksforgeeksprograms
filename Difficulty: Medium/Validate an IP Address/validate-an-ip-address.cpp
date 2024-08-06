//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
public:
    int isValid(string str) {
        int dot = 0;
        int n = str.size();
        
        for (int i = 0; i < n; ++i) {
            string ok = "";
            while (i < n && str[i] != '.') {
                ok += str[i];
                ++i;
            }
            if (i < n && str[i] == '.') {
                ++dot;
            }
            if (ok.empty() || ok.size() > 3 || stoi(ok) > 255 || (ok.size() > 1 && ok[0] == '0')) {
                return false;
            }
        }
        return dot == 3;
    }
};


//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends