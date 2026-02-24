int maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    
    int sum = 0;

    // First window
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    int maxi = sum; 

    // Slide window
    for (int i = k; i < n; i++) {
        sum += nums[i] - nums[i - k];
        maxi = max(maxi, sum);
    }

    return maxi;
}