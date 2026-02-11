class Solution {
    int atMost(vector<int> &nums,int k){
        unordered_map<int,int> m;
        int cnt=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    m.erase(nums[l]);
                }
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};