class Solution {
    bool isValid(vector<int>& nums,int day,int threshold){
        int sum=0;
        for(int d:nums){
            sum+=ceil((double)d/day);
            if(sum>threshold){
                return false;
            }
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int left=1;
        int right=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>right){
                right=nums[i];
            }
        }
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;

            if(isValid(nums,mid,threshold)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }

        return ans;
    }
};