class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int n=arr.size();
        
        for(int i=1;i<n;i++){
            int last=ans.back()[1];
            int currSt=arr[i][0];
            int currEnd=arr[i][1];

            if(currSt<=last){
                ans.back()[1]=max(last,currEnd);
            }else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};