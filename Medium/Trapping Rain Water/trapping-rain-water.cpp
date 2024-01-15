//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here 
            long long int l=0;
            long long int r=n-1;
            long long int lm=arr[0];
            long long int rm=arr[n-1];
            long long int  sum=0;
            while(l<r){
                if(lm<rm){
                    l+=1;
                    if(arr[l]<lm){
                        sum+=abs(lm-arr[l]);  
                    }
                    else{
                        lm=arr[l];
                    }
                    
                }
                else{
                    r-=1;
                    if(arr[r]<rm){
                        sum+=abs(rm-arr[r]);
                    }
                    else{
                        rm=arr[r];
                    }
                }
            }
            return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends