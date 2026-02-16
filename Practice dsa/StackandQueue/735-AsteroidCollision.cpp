class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> s;
        for(int a:asteroids){
            bool flag=false;
            while(!s.empty() && s.top()>0 && a<0){
                if(abs(a)>s.top()){
                    s.pop();
                }else if(abs(a)==s.top()){
                    s.pop();
                    flag=true;
                    break;
                }else{
                    flag=true;
                    break;
                }
            }
            if(!flag){
                s.push(a);
            }
        }
        vector<int> ans(s.size());
        for(int i=s.size()-1;i>=0;i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};