class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
            }
            maxi=max(maxi,nums[i]-mini);
        }

        return maxi;
    }
};
