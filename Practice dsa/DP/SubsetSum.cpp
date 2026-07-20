class Solution {
  public:
    vector<vector<int>> dp;
    
    bool solve(int index,vector<int>& arr,int sum){
        if(sum==0){
            return true;
        }
        if(index==0){
            return arr[0]==sum;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        bool take=0;
        if(arr[index]<=sum){
            take=solve(index-1,arr,sum-arr[index]);
        }
        bool not_take=solve(index-1,arr,sum);
        return dp[index][sum]=take || not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        dp.assign(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum);
    }
};