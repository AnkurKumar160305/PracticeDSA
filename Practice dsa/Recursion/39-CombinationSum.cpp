class Solution {
    void solve(vector<vector<int>>& ans,vector<int> output,int index,vector<int> candidates,int target){
        if(target==0){
            ans.push_back(output);
            return;
        }
        if(target<0 || index>=candidates.size()){
            return;
        }
        output.push_back(candidates[index]);
        solve(ans,output,index,candidates,target-candidates[index]);
        output.pop_back();
        solve(ans,output,index+1,candidates,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> output;
        vector<vector<int>> ans;
        solve(ans,output,0,candidates,target);
        return ans;
    }
};