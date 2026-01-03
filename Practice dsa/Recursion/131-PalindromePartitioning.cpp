class Solution {
    bool isPalindrome(string s,int st,int end){
        while(st<end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    void solve(int index,vector<string>& output,vector<vector<string>>& ans,string& s){
        if(index==s.length()){
            ans.push_back(output);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                output.push_back(s.substr(index,i-index+1));
                solve(i+1,output,ans,s);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        int index=0;
        solve(index,output,ans,s);
        return ans;
    }
};