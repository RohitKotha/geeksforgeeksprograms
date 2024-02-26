//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<string>v1;
	void fun(string s,int i,string st){
	    if(i>=s.size()){
	        v1.push_back(st);
	        return;
	    }
	    st.push_back(s[i]);
	    fun(s,i+1,st);
	    st.pop_back();
	    fun(s,i+1,st);
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    v1.clear();
		    fun(s,0,"");
		    sort(v1.begin(),v1.end());
		    v1.erase(v1.begin());
		    return v1;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends