//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long prod=1;
        long long MOD=1e9+7;
        sort(begin(arr),end(arr));
        long long neg=0,ze=0,pos=0;
        long long np=1,pp=1;
        long long ok=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                 np = (np * arr[i]) % MOD;
                
                    ok=i;
                
                neg++;
            }
            else if(arr[i]==0){
                ze+=1;
            }
            else if(arr[i]>0){
                pp = (pp * arr[i]) % MOD;
                pos++;
            }
        }
        //cout<<neg<<" "<<pos<<" "<<np<<" "<<pp;
        if(neg==0){
            if(pos==0){
                return 0;
            }
        }
        
        else if(neg==1 ){
            if(pos==0 and ze>0){
                return 0;
            }
            else if(pos==0 and ze==0){
            return np;    
            }
            
            else{
                np=1;
            }
            
        }
        else if(np<0 and neg>0 and  neg%2!=0){
            np = (np / arr[ok]) % MOD;
        }
        
      return (np * pp) % MOD;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends