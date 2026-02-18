int scoreBrackets(const string& s) {
    // add your code here
    stack<int> st;
    st.push(0);
    for(char c:s){
        if(c=='('){
            st.push(0);
        }else{
            int top=st.top();
            st.pop();
            int val=max(2*top,1);
            st.top()+=val;
        }
    }
    return st.top();
}