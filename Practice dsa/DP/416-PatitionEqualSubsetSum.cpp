class Solution {
    vector<vector<int>> dp;
    bool solve(int index,vector<int>& nums,int sum){
        if(sum==0){
            return true;
        }
        if(index==0){
            return nums[0]==sum;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        bool take=0;
        if(nums[index]<=sum){
            take=solve(index-1,nums,sum-nums[index]);
        }
        bool not_take=solve(index-1,nums,sum);

        return dp[index][sum]=take || not_take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        int s1=sum/2;
        if(sum%2==0){
            dp.assign(n,vector<int>(s1+1,-1));
            return solve(n-1,nums,s1);
        }
        return false;

    }
};