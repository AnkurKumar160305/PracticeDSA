class SpecialStack {
    stack<int> s1;
    stack<int> s2;
    public:
        
    void push(int data) {
        s1.push(data);
        if(s2.empty() || data <= s2.top()) {
            s2.push(data);
        } else {
            s2.push(s2.top());
        }

    }

    void pop() {
        if(s1.empty()){
            return;
        }
        s1.pop();
        s2.pop();
    }

    int top() {
        if(s1.empty()){
            return -1;
        }
        return s1.top();
    }

    int getMin() {
        if(s2.empty()){
            return -1;
        }
        return s2.top();
    }  
};

//Optimal
class SpecialStack {
    stack<long long> s;
    long long mini=INT_MAX;
    public:
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini=data;
        }else{
            if(data < mini) {
                s.push(2LL*data-mini);
                mini=data;
            } else {
                s.push(data);
            }
        }
    }

    void pop() {
        if(s.empty()){
            return;
        }
        long long curr=s.top();
        s.pop();
        if(curr<mini){
            mini=2*mini-curr;
        }
        
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        long long curr=s.top();
        if(curr<mini){
            return mini;
        }
        return curr;
    }

    int getMin() {
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};