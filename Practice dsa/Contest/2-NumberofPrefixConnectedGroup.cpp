class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        auto v=words;
        unordered_map<string,int> m;
        for(string &word:words){
            if(word.length()>=k){
                string pre=word.substr(0,k);
                m[pre]++;
            }
        }
        int cnt=0;
        for(auto i:m){
            if(i.second>=2){
                cnt++;
            }
        }
        return cnt;
    }
};