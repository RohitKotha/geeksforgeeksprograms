//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        if(s.size()==k){
            return 0;
        }
        if(s.size()-1==k){
            return 1;
        }
        unordered_map<char,int>mp;
        set<char>se;
        
        for (char ch : s) {
            //se.insert(ch);
        if(mp.find(ch)!=mp.end()){
            mp[ch]+=1;
        }
        else{
            mp[ch]=1;
        }
    }
    vector<int>v1;
    priority_queue<int>q1;
  for (const auto& it : mp) {
        v1.push_back(it.second);
        q1.push(it.second);
    }
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    int max1=0;
  int i=0;
  
        while(k!=0 and !q1.empty()){
            int ok=q1.top();
            q1.pop();
            ok-=1;
            
            if (ok > 0) {
                q1.push(ok);
            }
            k--;
        }
    
    int sum=0;
   while(!q1.empty()){
        sum+=pow(q1.top(),2);
        q1.pop();
    }

        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends