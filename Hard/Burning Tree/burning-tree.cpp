//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  unordered_map<int,vector<int>>mp;
  vector<int>v1;
  int cur=0;
  void fun(Node*root,Node*prev){
    //map<int,vector<int>>mp;
    if(root==NULL){
        return;
    }
    
        
        if(root->left!=NULL){
            mp[root->data].push_back(root->left->data);
        }
        if(root->right!=NULL){
            mp[root->data].push_back(root->right->data);
        }
        if(prev!=NULL){
            mp[root->data].push_back(prev->data);
        }
        
        fun(root->left,root);
        fun(root->right,root);
    
  }
  
  void letsburn(unordered_map<int,int>&ok,int gg,int target){
      if(ok.find(target)!=ok.end()){
          return;
      }
      if(mp.size()==ok.size()){
          return;
      }
      if(cur<gg){
          cur=gg;
      }
      ok[target] = 1;
      for (int i = 0; i < mp[target].size(); i++) {
            letsburn(ok, gg + 1, mp[target][i]);
        }
      
  }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        mp.clear();
        v1.clear();
        cur=0;
        if(root==NULL){
            return target;
        }
        fun(root,NULL);
        
        unordered_map<int,int>ok;
        letsburn(ok,0,target);
        
    return cur;
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends