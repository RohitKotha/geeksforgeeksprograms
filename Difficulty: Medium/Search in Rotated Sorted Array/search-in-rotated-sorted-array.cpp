//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n=arr.size();
        int l=0;
        int r=n-1;
        int mid=(l+r)/2;
        while(l<=r){
            mid=(l+r)/2;
            if(arr[mid]==key){
                return mid;
            }
            if(arr[l]<=arr[mid]){
                if(arr[l]<=key and arr[mid]>=key){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(arr[r]>=key and arr[mid]<=key){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends