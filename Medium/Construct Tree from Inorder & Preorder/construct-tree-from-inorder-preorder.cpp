//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    int index=0;
    public:
    int search(int start,int end,int in[],int t){
        int i;
        for(i=start;i<=end;i++){
            
            if(t==in[i]){
                break;
            }
        }
        return i;
    }
    //Node*root;
    Node* fun(int *in,int *pre,int start,int end){
        if(start>end){
            return NULL;
        }
        if(start==end){
            Node*nn=new Node(in[start]);
            index++;
            return nn;
        }
        int x = search(start,end,in,pre[index]);
        Node*root=new Node(in[x]);
        index++;
        root->left=fun(in,pre,start,x-1);
        root->right=fun(in,pre,x+1,end);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        

        return fun(in,pre,0,n-1);
        
    }
};






//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends