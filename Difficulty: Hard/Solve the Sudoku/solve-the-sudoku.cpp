//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    bool ok(vector<vector<int>> &mat,int i,int j,int num){
        for(int a=0;a<9;a++){
            if(mat[i][a]==num or mat[a][j]==num){
                return false;
            }
        }
        int sr=i-i%3,sc=j-j%3;
        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                if(mat[sr+a][sc+b]==num){
                    return false;
                }
            }
        }
        return true;
    }
    bool solver(vector<vector<int>> &mat){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]==0){
                    for(int k=1;k<=9;k++){
                        if(ok(mat,i,j,k)){
                            mat[i][j]=k;
                            if(solver(mat)){
                                return true;
                            }
                            mat[i][j]=0;
                        }
                    }
                   return false; 
                }
                
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solver(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends