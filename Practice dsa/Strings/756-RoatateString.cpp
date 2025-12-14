class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n=s.size();
        for(int i=0;i<n;i++){
            char temp=s[0];
            for(int j=1;j<n;j++){
                s[j-1]=s[j];
            }
            s[n-1]=temp;
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};


//Optimal
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string str=s+s;
        int index=str.find(goal);
        if(index==-1){
            return false;
        }
        return true;
    }
};