string binaryRemoval(string& s) {
    // add your code here
    stack<char> st;
    for(char c:s){
        if(!st.empty() && st.top()==c){
            st.pop();
        }else{
            st.push(c);
        }
    }
    string ans="";
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
    return ans;
    
}