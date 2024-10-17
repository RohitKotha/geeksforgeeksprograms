//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    // Function to split a linked list into two lists alternately
      vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        Node* t1=head;
        Node*k1=t1;
        Node* temp=head;
        if(temp->next==NULL){
            return {t1,NULL};
        }
        Node* t2=head->next;
        Node*k2=t2;
        
        temp=t2->next;
        while(temp){
            t1->next=temp;
            t1=t1->next;
            
            temp=temp->next;
            if(temp){
                
                t2->next=temp;
                t2=t2->next;
                
                temp=temp->next;
                
            }
        }
        t1->next=NULL;
        t2->next=NULL;
        return {k1,k2};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends