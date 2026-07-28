class Solution {
    vector<vector<int>> dp;
    int solve(int start,int end,vector<int>& nums){
        if(start==end){
            return nums[start];
        }

        if(dp[start][end]!=-1) return dp[start][end];

        int take=nums[start]-solve(start+1,end,nums);
        int not_take=nums[end]-solve(start,end-1,nums);
        
        return dp[start][end]=max(take,not_take);
        
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0, n - 1, nums) >= 0;
    }
};