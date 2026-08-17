class Solution {
    void solve(vector<vector<int>>& ans,vector<int>& output,int index,int k,int n,int cnt){

    if(cnt==k){
        if(n==0){
            ans.push_back(output);
        }
        return;
    }
    if(n<=0){
        return;
    }
    for(int i=index;i<=9;i++){
        // If i is already greater than remaining sum,
        // further numbers will also be too large.
        if (i > n) {
            break;
        }
        output.push_back(i);
        solve(ans,output,i+1,k,n-i,cnt+1);
        output.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> output;
        vector<vector<int>> ans;
        solve(ans,output,1,k,n,0);
        return ans;
    }
};