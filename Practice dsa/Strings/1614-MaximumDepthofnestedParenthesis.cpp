class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxi=0;
        for(auto i:s){
            if(i=='('){
                cnt++;
                maxi=max(maxi,cnt);
            }else if(i==')'){
                cnt--;
            }
        }
        return maxi;
    }
};