class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long maxi=0,mini=0;

        for(int i=0;i<k;i++){
            maxi+=nums[n-1-i];
            mini+=nums[i];
        }
        return abs(maxi-mini);
    }
};