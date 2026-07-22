class Solution {
    vector<int> dp;

    int solve(int index, vector<int>& nums) {
        if(index < 0) return 0;

        if(dp[index] != -1)
            return dp[index];

        int take = nums[index] + solve(index - 2, nums);
        int notTake = solve(index - 1, nums);

        return dp[index] = max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> first(nums.begin(), nums.end() - 1);
        vector<int> second(nums.begin() + 1, nums.end());

        dp.assign(first.size(), -1);
        int ans1 = solve(first.size() - 1, first);

        dp.assign(second.size(), -1);
        int ans2 = solve(second.size() - 1, second);

        return max(ans1, ans2);
    }
};