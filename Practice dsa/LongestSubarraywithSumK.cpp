class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int l=0;
        int n=nums.size();
        int sum=0,maxi=0;

        for(int r=0;r<n;r++){
            sum+=nums[r];

            while(sum>k){
                sum-=nums[l];
                l++;
            }
            if(sum==k){
                maxi=max(maxi,r-l+1);
            }
        }

        return maxi;
    }
};