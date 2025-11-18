class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int next=(i+1)%n;
            if(nums[i]>nums[next]){
                cnt++;
            }
        }
        return cnt<=1;
    }
};