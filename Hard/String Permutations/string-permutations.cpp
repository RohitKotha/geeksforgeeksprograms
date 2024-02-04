//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string>v1;
    
    void per(string s,int start,int end){
    if (start >= end){ 
        v1.push_back(s);
        return ;
        }
        
    for (int i = start ; i<=end ; i++){
        
        swap(s[start],s[i]);
        
        per(s,start+1,end);
        
        swap(s[start],s[i]);
        
    }
}
    
    vector<string> permutation(string s)
    {
        
        int co=0;
        per(s,0,s.size()-1);
        sort(v1.begin(),v1.end());
        return v1;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends