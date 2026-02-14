class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        int i=0;
        long long sum=0;
        while(i<n){
            long long maxi=nums[i];
            int j=i+1;
            while(j<n && colors[j]==colors[i]){
                maxi=max(maxi,(long long)nums[j]);
                j++;
            }
            sum+=maxi;
            i=j;
        }
        return sum;
    }
};©leetcode