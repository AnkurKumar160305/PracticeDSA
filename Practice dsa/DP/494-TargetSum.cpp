class Solution {
    vector<vector<int>> dp;
    int solve(int index,vector<int>& nums,int target){
        if (index == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || target == nums[0]) return 1;
            return 0;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int take=0;
        if(nums[index]<=target){
            take=dp[index][target]=solve(index-1,nums,target-nums[index]);
        }
        int not_take=solve(index-1,nums,target);

        return dp[index][target]=take+not_take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if (abs(target) > sum) return 0;
        if((target+sum)%2==0){
            int s1=(target+sum)/2;
            dp.assign(n,vector<int>(s1+1,-1));
            return solve(n-1,nums,s1);
        }
        return 0;
    }
};