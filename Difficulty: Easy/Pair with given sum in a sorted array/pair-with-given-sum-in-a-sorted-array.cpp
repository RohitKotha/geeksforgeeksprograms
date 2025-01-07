//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
    int ans=0;
        int n=arr.size();
        int i=0;
        int j=n-1;
        int sum=0;
       while(i<j){
            sum=arr[i]+arr[j];
            if(sum<target){
                i++;
            }else if(sum>target){
                j--;
            }else{
                
               int left=1,right=1;
                while(i<n-1 and arr[i]==arr[i+1] ){
                    left++;
                   i++;
                }
                
                while(j-1>i and arr[j]==arr[j-1] ){
                    right++;
                    j--;
                }
                if(arr[i]==arr[j]){
                    ans+=(left*(left-1))/2;
                    break;
                }else{
                    ans+=left*right;
                }
            i++;
            j--;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends