//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    long long ans=1;
		    while(n>=1){
		    if(n%2!=0){
		        ans=(ans*x)%M;
		        n--;
		    }
		    x=(x*x)%M;
		    n=n/2;
		        
		    }
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends