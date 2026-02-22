vector<int> nextHigherTemperatures(vector<int>& t) {
    // add your code here
    stack<int> s;
    vector<int> ans(t.size(),-1);
    for(int i=2*t.size()-1;i>=0;i--){
        int idx=i%t.size();
        while(!s.empty() && t[s.top()]<=t[idx]){
            s.pop();
        }
        if(i<t.size()){
            if(!s.empty()){
                ans[idx]=t[s.top()];
            }
        }
        s.push(idx);
    }
    return ans;
}