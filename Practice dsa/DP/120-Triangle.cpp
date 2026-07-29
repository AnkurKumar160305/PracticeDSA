class Solution {
    vector<vector<int>> dp;
    vector<vector<bool>> vis;

    int solve(int row, int col, vector<vector<int>>& triangle) {

        if (row == triangle.size() - 1)
            return triangle[row][col];

        if (vis[row][col])
            return dp[row][col];

        int down = triangle[row][col] + solve(row + 1, col, triangle);
        int diag = triangle[row][col] + solve(row + 1, col + 1, triangle);

        vis[row][col] = true;
        return dp[row][col] = min(down, diag);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        dp.assign(n, vector<int>(n, 0));
        vis.assign(n, vector<bool>(n, false));

        return solve(0, 0, triangle);
    }
};