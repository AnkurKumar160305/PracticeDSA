class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if(str.empty()) return "";
        string ref=str[0];

        for(int i=1;i<str.size();i++){
            int j=0;
            while(j<str[i].size() &&  j<ref.size() && str[i][j]==ref[j]){
                j++;
            }
            ref=ref.substr(0,j);
            if(ref.empty()) return "";
        }
        return ref;
    }
};