class Solution {
    int countTime(vector<int>& nums,int mid){
        int sum=0;
        int count=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sum+nums[i]>mid){
                count++;
                sum=nums[i];
            }else{
                sum+=nums[i];
            }
        }
        return count;
    }
public:
    int Painters(vector<int>& nums, int k) {

        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);

        while(left<right){
            int mid=left+(right-left)/2;
            if(countTime(nums,mid)<=k){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};