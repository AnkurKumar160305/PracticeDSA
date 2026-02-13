#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int, int> freq;
    
    // Count frequency
    for(int num : nums) {
        freq[num]++;
    }
    
    vector<int> result;
    
    // Collect elements that appear exactly twice
    for(auto &it : freq) {
        if(it.second == 2) {
            result.push_back(it.first);
        }
    }
    
    // Sort in increasing order
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    vector<int> nums = {1,2,2,3,3,3,4,4};

    vector<int> ans = findDuplicates(nums);

    if(ans.empty()) {
        cout << "[]";
    } else {
        for(int x : ans)
            cout << x << " ";
    }

    return 0;
}
