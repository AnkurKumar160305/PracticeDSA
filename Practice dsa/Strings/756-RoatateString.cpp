class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size() != goal.size()) return false;
        for(int i=0;i<n;i++){
            if(s==goal){
                return true;
            }
            char ch=s.back();
            s.pop_back();
            s=ch+s;
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