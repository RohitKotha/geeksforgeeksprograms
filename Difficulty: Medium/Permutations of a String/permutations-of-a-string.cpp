//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<string>v1;
    void per(string s,int start,int end){
    if (start >= end){ 
        v1.push_back(s);
        return ;
        }
        
    for (int i = start ; i<=end ; i++){
        
        swap(s[start],s[i]);
        
        per(s,start+1,end);
        
        swap(s[start],s[i]);
        
    }
}
	public:
		vector<string>findPermutation(string s)
		{
		    
            int co=0;
            per(s,0,s.size()-1);
            sort(v1.begin(),v1.end());
            v1.erase(unique(v1.begin(), v1.end()), v1.end());
            return v1;
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends