//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        unordered_map<int, int> mp;
        int threshold = nums.size() / 3;
        vector<int> ans;

        // Count occurrences of each element
        for (int num : nums) {
            mp[num]++;
        }

        // Check which elements meet the majority criteria
        for (const auto& m : mp) {
            if (m.second > threshold) {
                ans.push_back(m.first);
            }
        }

        // If no majority elements are found, return -1
        if (ans.empty()) {
            return {-1};
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends