class Solution {
public:
    string convertToTitle(int c) {
        string ans="";
        while(c>0){
            c--;
            char ch='A'+ (c%26);
            ans=ch+ans;
            c=c/26;
        }
        return ans;
    }
};