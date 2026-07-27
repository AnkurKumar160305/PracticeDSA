class Solution {
    vector<vector<int>> dp;

    bool solve(int index, vector<int>& arr, int target) {

        if(target == 0) return dp[index][target] = true;

        if(index == 0) return dp[index][target] = (arr[0] == target);

        if(dp[index][target] != -1) return dp[index][target];

        int take = false;
        if(arr[index] <= target){
            take = solve(index-1, arr, target-arr[index]);
        }
        int notTake = solve(index-1, arr, target);

        return dp[index][target] = take || notTake;
    }
  public:
    int minDifference(vector<int>& arr) {
        // code here
        int n=arr.size();
        int total = 0;
        for(int x : arr) total += x;
        
        // s1+s2=total;
        // s1-s2=minDiff;
        // 2s1-total=miDiff


        dp.assign(n, vector<int>(total+1,-1));
        
        for(int i=0;i<=total;i++){
            solve(n-1, arr, i);
        }
        int mini=INT_MAX;
        for(int s1=0;s1<=total/2;s1++){
            if(dp[n-1][s1]==1){
                mini=min(mini,total-2*s1);
            }
        }
        
        return mini;
        
    }
};
