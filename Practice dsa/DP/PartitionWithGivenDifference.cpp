class Solution {
    vector<vector<int>> dp;

    int solve(int index, vector<int>& arr, int target) {

        if(index == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if(dp[index][target] != -1) return dp[index][target];

        int take = 0;
        if(arr[index] <= target){
            take = solve(index-1, arr, target-arr[index]);
        }
        int notTake = solve(index-1, arr, target);

        return dp[index][target] = take + notTake;
    }

public:
    int countPartitions(vector<int>& arr, int diff) {

        int total = 0;
        for(int x : arr) total += x;

        if(total - diff < 0) return 0;
        if((total - diff) % 2) return 0;

        int target = (total - diff) / 2;

        dp.assign(arr.size(), vector<int>(target+1, -1));

        return solve(arr.size()-1, arr, target);
    }
};