//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool hehe=true;
    void fun(int arr[],int n,int i){
        
        for(int i=0;i<n;i++){
            if(2*i+1<n){
                if(arr[i]<arr[2*i+1]){
                hehe=false;
                    break;
                }
            }
            if(2*i+2<n){
                if(arr[i]<arr[2*i+2]){
                hehe=false;
                    break;
                }
            }
            
        }
        
        
    }
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        fun(arr,n,0);
        return hehe;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends