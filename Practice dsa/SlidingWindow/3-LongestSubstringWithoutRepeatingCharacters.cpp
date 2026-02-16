class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int left=0,maxi=0;
        for(int i=0;i<s.size();i++){
            while(m.count(s[i])){
                m.erase(s[left]);
                left++;
            }
            m.insert(s[i]);
            maxi=max(maxi,i-left+1);
        }
        return maxi;
    }
};