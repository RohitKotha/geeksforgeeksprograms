//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int maxi=-10;
        int ip=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi=arr[i];
                //cout<<arr[i]<<" ";
                ip=i;  
            }
        }
    //    cout<<endl<<maxi<<endl;
        int maxi2=-10;
        for(int i=0;i<arr.size();i++){
            
            if(maxi2<arr[i] and i!=ip){
                maxi2=arr[i];
          //      cout<<arr[i]<<" ";
            }
           // maxi2=max(maxi2,arr[i]);
        }
  //      cout<<endl<<maxi2<<endl;
        return maxi+maxi2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends