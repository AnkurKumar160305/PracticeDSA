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
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int x : stones) sum += x;

        int target = sum / 2;
        int n = stones.size();

        dp.assign(n, vector<int>(target + 1, -1));

        for(int i=0;i<=target;i++){
            solve(n-1,stones,i);
        }

        int mini=INT_MAX;
        for(int s1=0;s1<=target;s1++){
            if(dp[n-1][s1]==1){
                mini=min(mini,sum-2*s1);
            }
        }
        return mini;
    }
};