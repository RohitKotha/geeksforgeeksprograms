//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minRemoval(vector<vector<int>> &arr) {
        // code here
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    int c=0;
    int cur=0;
    for(int i=1;i<arr.size();i++){
        if(arr[cur][1]>arr[i][0]){
            c++;
        }else{
            cur=i;
        }
    }
    return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends