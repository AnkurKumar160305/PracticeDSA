class Solution {
    void rev(queue<int> &q,int k){
        if(k==0){
            return; 
        }
        int top=q.front();
        q.pop();
        rev(q,k-1);
        q.push(top);
    }
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k>q.size()){
            return q;
        }
        rev(q,k);
        
        int rem=q.size()-k;
        while(rem--){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};




//OR
queue<int> reverseFirstK(queue<int> q, int k) {

    stack<int> s;

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back into queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move remaining elements to back
    int t = q.size() - k;
    while (t--) {
        q.push(q.front());
        q.pop();
    }

    return q;
}
