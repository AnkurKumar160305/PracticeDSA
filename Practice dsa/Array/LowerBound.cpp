
// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.
class Solution {
public:
    int LowerBound(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int index=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target){
                index=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        } 
        return index;
    }
};

class Solution {
public:
    int UpperBound(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int index=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<=target){
                left=mid+1;
            }else{
                index=mid;
                right=mid-1;
            }
        } 
        return index;
    }
};