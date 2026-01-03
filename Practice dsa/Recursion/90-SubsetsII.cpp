class Solution {
    void solve(int index,vector<int>& output,vector<vector<int>>& ans,vector<int> nums){
        
        ans.push_back(output);
        
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            output.push_back(nums[i]);
            solve(i+1,output,ans,nums);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(0,output,ans,nums);
        return ans;
    }
};