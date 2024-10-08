//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        vector<int>bit(32,0);
        for(int i=0;i<n;i++){
         int temp=arr[i];
         int j=0;
         while(temp){
             if(temp&1){
                 bit[j]++;
                 
             }
             j++;
             temp>>=1;
             
         }
        }
         long long ans =0;
         for(int i=0;i<bit.size();i++){
             long long temp=bit[i];
             temp--;
             long long pair=(temp*(temp+1))/2;
             ans+=(pair*(long long)pow(2,i));
        
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends