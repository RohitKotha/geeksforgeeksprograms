//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
            //code here.
           if(n==0){
               return 0;
           }
        int a=n/2;
        int b=n/3;
        int c=n/4;
        int sum=a+b+c;
        return max({n,sum,maxSum(a)+maxSum(b)+maxSum(c)});
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends