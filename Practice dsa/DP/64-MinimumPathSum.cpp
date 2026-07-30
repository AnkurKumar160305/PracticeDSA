class Solution {
    vector<vector<int>> dp;
    int solve(int row,int col,vector<vector<int>>& grid){
        if(row >= grid.size() || col >= grid[0].size()){
            return 1e9;
        }
        if(row == grid.size()-1 && col == grid[0].size()-1){
            return grid[row][col];
        }
        if(dp[row][col]!=INT_MAX) return dp[row][col];

        int down=grid[row][col]+solve(row+1,col,grid);
        int right=grid[row][col]+solve(row,col+1,grid);

        return dp[row][col]=min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<int>(n, INT_MAX));
        return solve(0,0,grid);
    }
};