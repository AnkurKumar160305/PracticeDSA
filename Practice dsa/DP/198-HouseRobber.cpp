class Solution {
    vector<int> dp;
    int solve(int index,vector<int>& nums){
        if(index < 0) return 0;
        if(index == 0) return nums[0];

        if(dp[index]!=-1) return dp[index];

        int take=nums[index]+solve(index-2,nums);
        int not_take=solve(index-1,nums);
        return dp[index]=max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n, -1);
        return solve(n-1, nums);
    }
};