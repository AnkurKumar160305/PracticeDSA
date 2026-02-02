class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int cnt=2;
        for(int i=2;i<nums.size();i++){
            if(nums[cnt-2]!=nums[i]){
                nums[cnt++]=nums[i];
            }
        }
        return cnt;

    }
};