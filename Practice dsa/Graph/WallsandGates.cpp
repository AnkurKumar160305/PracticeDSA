#include <bits/stdc++.h> 
vector<vector<int>> wallsAndGates(vector<vector<int>> &mat, int n, int m) {
    // Write your code here.

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist = mat;

        queue<pair<pair<int, int>, int>> q;

        // Push all 0's into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }else if(mat[i][j]==-1){
                    vis[i][j] = 1;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[row][col] = steps;

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }

        return dist;
}