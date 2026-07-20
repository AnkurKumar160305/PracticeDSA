class Solution {
    public:
    
    int knap(int index,int W,vector<int>& val,vector<int>& wt){
        
        if(index == 0){
            if(wt[0] <= W)
                return val[0];
            return 0;
        }
        int take = 0, not_take = 0;
        if(W>=wt[index]){
            take=val[index]+knap(index-1,W-wt[index],val,wt);
        }else{
            not_take=knap(index-1,W-wt[index],val,wt);
        }
        return max(take,not_take);
        
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int index=wt.size()-1;
        return knap(index,W,val,wt);
    }
};


//Using DP
class Solution {
    public:
    vector<vector<int>> dp;
    
    int knap(int index,int W,vector<int>& val,vector<int>& wt){
        if(index == 0){
            if(wt[0] <= W)
                return val[0];
            return 0;
        }
        
        if(dp[index][W]!=-1) return dp[index][W];
        
        int take = 0;
        if(W>=wt[index]){
            take=val[index]+knap(index-1,W-wt[index],val,wt);
        }
        int not_take = knap(index-1, W, val, wt);
        
        return dp[index][W]=max(take,not_take);
        
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n=wt.size();
        dp.assign(n,vector<int>(W+1,-1));
        return knap(n-1,W,val,wt);
    }
};