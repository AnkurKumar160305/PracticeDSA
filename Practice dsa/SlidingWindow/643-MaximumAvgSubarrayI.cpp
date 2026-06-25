class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        double sum=0.0;
        double maxavg=INT_MIN;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            if(r-l+1>k){
                sum-=nums[l];
                l++;
            }
            if(r-l+1==k){
                maxavg=max(maxavg,sum/(r-l+1));
            }
        }
        return maxavg;
    }
};