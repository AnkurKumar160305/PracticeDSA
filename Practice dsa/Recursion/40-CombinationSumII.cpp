class Solution {
    void solve(vector<vector<int>>& ans,vector<int>& output,int index,vector<int>& candidates,int target){
        if(target==0){
            ans.push_back(output);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i] == candidates[i - 1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            output.push_back(candidates[i]);
            solve(ans,output,i+1,candidates,target-candidates[i]);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<int> output;
        vector<vector<int>> ans;
        solve(ans,output,0,candidates,target);
        return ans;
    }
};