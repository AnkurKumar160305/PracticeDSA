class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        char m1[256] = {0};
        char m2[256] = {0};

        for(int i = 0; i < s.size(); i++) {
            if((m1[s[i]] && m1[s[i]] != t[i]) || (m2[t[i]] && m2[t[i]] != s[i]))
                return false;
            
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }

        return true;
    }
};