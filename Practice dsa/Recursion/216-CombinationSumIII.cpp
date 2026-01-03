class Solution {
    void solve(int start,vector<vector<int>>& ans,vector<int>& output,int k,int n){
        if(output.size()==k){
            if(n==0){
                ans.push_back(output);
                return;
            }
        }
        for(int i=start;i<=9;i++){
            if(i>n){
                break;
            }
            output.push_back(i);
            solve(i+1,ans,output,k,n-i);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(1,ans,output,k,n);
        return ans;
    }
};