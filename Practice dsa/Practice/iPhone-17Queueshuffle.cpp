

queue<int> reverseLastK(queue<int> q, int k) {
    // add your code here
    int n=q.size();
    if(n<k || k<=0){
        return q;
    }
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    return q;
}