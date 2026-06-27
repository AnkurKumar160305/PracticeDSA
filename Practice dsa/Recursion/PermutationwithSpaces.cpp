class Solution {
    
    void solve(string& s,int index,vector<string>& ans,string path){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        solve(s,index+1,ans,path+" "+s[index]);
        solve(s,index+1,ans,path+s[index]);
    }
  public:

    vector<string> permutation(string s) {
        // Code Here
        vector<string> ans;
        string path="";
        path+=s[0];
        solve(s,1,ans,path);
        return ans;
    }
};

//Recursion tree
//               A
//      A b              Ab
// A b c   A bc      Ab c   Abc