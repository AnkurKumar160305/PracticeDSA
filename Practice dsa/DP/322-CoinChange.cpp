class Solution {
    vector<vector<int>> dp;
    int solve(int index,vector<int>& coins,int amount){
        if(index==0){
            if(amount%coins[index]==0){
                return amount/coins[index];
            }
            return 1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];

        int take=1e9;
        if(coins[index]<=amount){
            take=1+solve(index,coins,amount-coins[index]);
        }
        int not_take=solve(index-1,coins,amount);
        return dp[index][amount]=min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins,amount);
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};