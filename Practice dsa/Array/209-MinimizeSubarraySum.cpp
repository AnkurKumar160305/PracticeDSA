class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int left=0;
        int sum=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=k){
                mini=min(mini,i-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return mini == INT_MAX ? 0 : mini;
    }
};