class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        unordered_map<char,int> m;

        int most=0;
        int maxi=0;
        for(int right=0;right<s.size();right++){
            m[s[right]]++;
            maxi=max(maxi,m[s[right]]);
            while(right-left+1-maxi>k){
                m[s[left]]--;
                if(m[s[left]]==0){
                    m.erase(s[left]);
                }
                left++;
            }
            most=max(most,right-left+1);
        }

        return most;
    }
};