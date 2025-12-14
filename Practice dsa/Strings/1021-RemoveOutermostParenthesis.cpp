class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int cnt=0;
        for(char ch:s){
            if(ch=='('){
                if(cnt>0){
                    result+=ch;
                }
                cnt++;
            }else{
                cnt--;
                if(cnt>0){
                    result+=ch;
                }
            }
        }
        return result;
    }
};