#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int first=target-nums[i];
        if(mp.find(first)!=mp.end()){
            return {mp[first],i};
        }
        mp[nums[i]]=i;
    }

    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
}