class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0,right=0;
        int ans=0;
        long curr=0;
        while(right<nums.size()){
            long target=nums[right];
            curr+=target;
            while((right-left+1)*target-curr>k){
                curr-=nums[left];
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};