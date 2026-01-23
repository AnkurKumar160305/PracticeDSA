class Solution {
    int countSplit(vector<int>& nums,int mid){
        int first=0;
        int count=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(first+nums[i]>mid){
                count++;
                first=nums[i];
            }else{
                first+=nums[i];
            }
        }
        return count;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        while(left<right){
            int mid=left+(right-left)/2;
            if(countSplit(nums,mid)<=k){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};