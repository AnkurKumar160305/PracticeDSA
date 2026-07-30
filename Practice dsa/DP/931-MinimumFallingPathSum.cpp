class Solution {
    vector<vector<int>> dp;

    int solve(int row, int col, vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Out of bounds
        if (col < 0 || col >= n)
            return 1e9;

        // Last row
        if (row == n - 1)
            return matrix[row][col];

        // Already computed
        if (dp[row][col] != INT_MAX)
            return dp[row][col];

        int down = matrix[row][col] + solve(row + 1, col, matrix);
        int leftDown = matrix[row][col] + solve(row + 1, col - 1, matrix);
        int rightDown = matrix[row][col] + solve(row + 1, col + 1, matrix);

        return dp[row][col] = min({down, leftDown, rightDown});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        dp.assign(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;

        // Try every starting column in the first row
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix));
        }

        return ans;
    }
};