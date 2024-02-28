//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    long long fun(string s){
        long long n=0;
        for(int i=0;i<s.size();i++){
            n=n*10+s[i]-'0';
        }
        return n;
    }
    int DivisibleByEight(string s){
        //code here
        long long ok=fun(s);
        return ok%8==0?1:-1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends