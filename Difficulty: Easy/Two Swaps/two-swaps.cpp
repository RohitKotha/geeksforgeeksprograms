//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        vector<int>a1;
        int diff=0;
        for(int i=0;i<arr.size();i++){
            a1.push_back(arr[i]);
        }
        sort(begin(a1),end(a1));
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=a1[i]){
                diff++;
            }
        }
        return diff<5;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends