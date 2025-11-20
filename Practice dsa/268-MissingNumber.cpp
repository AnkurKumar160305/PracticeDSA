class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xoor=n;
        for(int i=0;i<n;i++){
            xoor^=i^nums[i];
        }
        return xoor;
    }
};

//OR

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        int actualsum=0;
        for(int i=0;i<n;i++){
            actualsum+=nums[i];
        }
        return sum-actualsum;
    }
};