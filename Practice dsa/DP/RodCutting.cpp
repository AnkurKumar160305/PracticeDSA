class Solution {
    vector<vector<int>> dp;
    int solve(int i,vector<int>& price,int W){
        if(i==1){
            return W * price[0];
        }
        if(dp[i][W]!=-1) return dp[i][W];
        
        int take=0;
        if(i<=W){
            take=price[i-1]+solve(i,price,W-i);
        }
        int not_take=solve(i-1,price,W);
        return dp[i][W]=max(take,not_take);
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(n,price,n);
        
    }
};