class Solution {
        vector<vector<long long>> dp;
        long long solve(int index,vector<int>& coins,int amount){
            if(index==0){
                if(amount%coins[index]==0){
                    return 1;
                }
                return 0;
            }
            if(dp[index][amount]!=-1) return dp[index][amount];

            long long take=0;
            if(coins[index]<=amount){
                take=solve(index,coins,amount-coins[index]);
            }
            long long not_take=solve(index-1,coins,amount);
            return dp[index][amount]=(long long)take+(long long)not_take;
        }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n,vector<long long>(amount+1,-1));
        return solve(n-1,coins,amount);
    }
};