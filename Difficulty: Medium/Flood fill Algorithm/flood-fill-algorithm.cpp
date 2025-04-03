//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        int oldColor = image[sr][sc];

        if (oldColor == newColor) return image; 

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q1;
        q1.push({sr, sc});
        vis[sr][sc] = 1;
        image[sr][sc] = newColor;

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while (!q1.empty()) {
            int nr = q1.front().first;
            int nc = q1.front().second;
            q1.pop();

            for (int i = 0; i < 4; i++) {
                int nro = nr + dRow[i];
                int nco = nc + dCol[i];

                if (nro >= 0 && nro < n && nco >= 0 && nco < m && !vis[nro][nco] && image[nro][nco] == oldColor) {
                    vis[nro][nco] = 1;
                    image[nro][nco] = newColor;
                    q1.push({nro, nco});
                }
            }
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends