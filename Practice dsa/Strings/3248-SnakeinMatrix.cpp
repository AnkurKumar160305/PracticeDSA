class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int m=commands.size();
        vector<int> ans;
        int r=0,c=0;
        for(int i=0;i<m;i++){
            if(commands[i]=="RIGHT"){
                c++;
            }else if(commands[i]=="DOWN"){
                r++;
            }else if(commands[i]=="UP"){
                r--;
            }else{
                c--;
            }
        }
        return r*n+c;
    }
};