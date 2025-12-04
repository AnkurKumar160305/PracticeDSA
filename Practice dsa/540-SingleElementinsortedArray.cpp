class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if ((mid == left || nums[mid] != nums[mid - 1]) &&
                (mid == right || nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }
            if(mid>left && nums[mid]==nums[mid-1]){
                if((mid-left+1)%2!=0){
                    right=mid-2;
                }else{
                    left=mid+1;
                }
            }else if(mid<right && nums[mid]==nums[mid+1]){
                if((right-mid+1)%2!=0){
                    left=mid+2;
                }else{
                    right=mid-1;
                }
            }
        }
        return nums[left];
    }
};


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;

            if(mid%2==1){
                mid--;
            }
            if(nums[mid]==nums[mid+1]){
                left=mid+2;
            }else{
                right=mid;
            }
        }
        return nums[left];
    }
};