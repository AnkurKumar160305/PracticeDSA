class Solution {
    void Middle(int cnt,int mid,stack<int>& s){
        if(cnt==mid){
            s.pop();
            return;
        }
        int t=s.top();
        s.pop();
        Middle(cnt+1,mid,s);
        s.push(t);
    }
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        int n=s.size();
        int midBottom=(n+1)/2;
        int midTop=n-midBottom+1;
        Middle(1,midTop,s);
    }
};