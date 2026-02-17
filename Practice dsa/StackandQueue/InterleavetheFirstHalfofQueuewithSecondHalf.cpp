class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        stack<int> s1;
        stack<int> s2;
        stack<int> s;
        int cnt=0;
        while(cnt<n/2){
            int top=q.front();
            q.pop();
            s1.push(top);
            cnt++;
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            s2.push(top);
        }
        while(!s1.empty() && !s2.empty()){
            s.push(s2.top());
            s.push(s1.top());
            s1.pop();
            s2.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        
    }
};