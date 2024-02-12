//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
int mod= 1e9+7;
    long long fun(int n,int s,int pos){
        if(pos>n){
            return 0;
        }
        long long ans=1;
        for(int i=0;i<pos;i++){
            ans=ans*s;
            ans=ans%mod;
            s++;
        }
        ans+=fun(n,s,pos+1);
        ans=ans%mod;
        return ans;
    }
    long long sequence(int n){
        // code here
        return fun(n,1,1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends