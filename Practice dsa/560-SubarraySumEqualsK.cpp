class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size();
        m[0]=1;
        int sum=0,cnt=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            if(m.find(sum-k)!=m.end()){
                cnt+=m[sum-k];
            }
            m[sum]++;
        }

        return cnt;
    }
};