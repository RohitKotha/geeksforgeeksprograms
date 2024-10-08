//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> minAnd2ndMin(int a[], int n) {
    vector<int>v1;
    for(int i=0;i<n;i++){
        v1.push_back(a[i]);
    }
    sort(v1.begin(),v1.end());
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
    if(v1.size()==1){
        vector<int>ok;
        ok.push_back(-1);
        return ok;
    }
    return v1;
}