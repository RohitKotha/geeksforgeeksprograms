//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& nums) {
        // Your code here
      vector<vector<int>>v1;
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for (auto it : mp) {
            v1.push_back({it.first, it.second});
        }

        // Sort based on frequency and then by value in descending order
        sort(begin(v1), end(v1), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] > b[1]) || (a[1] == b[1] && a[0] < b[0]);
        });
        vector<int>ans;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v1[i][1];j++){
                ans.push_back(v1[i][0]);
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends