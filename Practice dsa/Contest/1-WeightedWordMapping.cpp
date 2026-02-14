class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string &word:words){
            int sum=0;
            for(char ch:word){
                if(ch>='a' && ch<='z'){
                    sum+=weights[ch-'a'];
                }
            }
            int mod=sum%26;
            ans+=char('z'-mod);
        }
        return ans;
    }
};