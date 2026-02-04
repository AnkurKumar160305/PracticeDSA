int solve(const vector<int>& nums) { 
    vector<int> need=nums;
    int cnt=0;
    sort(need.begin(),need.end());
    for(int i=0;i<nums.size();i++){
        if(need[i]!=nums[i]){
            cnt++;
        }
    }
    return cnt;
}
