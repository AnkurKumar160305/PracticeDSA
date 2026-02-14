class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        auto t=nums;
        if(n==1){
            return nums[0]; 
        }
        long long prev2=0;
        long long prev1=nums[0];
        for(int i=1;i<n;i++){
            long long take;
            if(colors[i]==colors[i-1]){
                take=nums[i]+prev2;
            }else{
                take=nums[i]+prev1;
            }
            long long curr=max(prev1,take);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};