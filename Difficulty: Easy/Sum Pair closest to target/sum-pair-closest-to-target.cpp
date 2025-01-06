//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        if(n<2){
            return {};
        }
        sort(arr.begin(),arr.end());
        pair<int,int>cp;
        int cd=INT_MAX;
        int i=0,j=n-1;
        int diff;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum==target){
                return {arr[i],arr[j]};
            }
            else if(cd>abs(target-sum)){
                cd=abs(sum-target);
                cp=make_pair(arr[i],arr[j]);
                diff=arr[j]-arr[i];
            }else if(cd==abs(target-sum)){
                int df=arr[j]-arr[i];
                if(diff<df){
                cp=make_pair(arr[i],arr[j]);
                diff=arr[j]-arr[i];
                }
            }
            if(sum>=target){
                j--;
            }else{
                i++;
            }
        }
        return {cp.first,cp.second};
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends