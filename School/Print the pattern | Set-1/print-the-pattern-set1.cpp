//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void printPat(int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
    printPat(n);
    cout<<endl;
	}
}
// } Driver Code Ends


/*You are required to complete this method*/
void printPat(int n)
{
    int lines = n;
    while(lines>0)
    {
        for(int i=n;i>0;i--)
        {
            int count=0;
            while(count<lines)
            {
                cout<<i<<" ";
                count++;
            }
        }
        lines--;
        cout<<"$";
    }
}