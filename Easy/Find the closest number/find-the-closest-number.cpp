//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        vector<int>v1;
        for(int i=0;i<n;i++){
            v1.push_back(abs(k-arr[i]));
        }
        int ok=INT_MAX;
        
        int num=0;
        for(int i=0;i<n;i++){
         if(ok>=v1[i]){
             
             if(ok==v1[i]){
                 if(num<arr[i]){
                     num=arr[i];
                 }
             }else{
                 num=arr[i];
             }
             ok=v1[i];
         }
        }
        return num;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends