int sumSubarrayMins(vector<int>& arr) {
    // add your code here
    int sum=0;
    for(int i=0;i<arr.size();i++){
        int mini=INT_MAX;
        for(int j=i;j<arr.size();j++){
            mini=min(mini,arr[j]);
            sum+=mini;
        }
    }
    return sum;
}



//Optimal
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    const int MOD = 1e9 + 7;
    
    vector<int> left(n), right(n);
    stack<int> st;

    // Previous Smaller Element
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        
        if(st.empty())
            left[i] = i + 1;
        else
            left[i] = i - st.top();
        
        st.push(i);
    }

    // Clear stack
    while(!st.empty()) st.pop();

    // Next Smaller Element
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        
        if(st.empty())
            right[i] = n - i;
        else
            right[i] = st.top() - i;
        
        st.push(i);
    }

    long long sum = 0;

    for(int i = 0; i < n; i++) {
        sum = (sum + (long long)arr[i] * left[i] * right[i]) % MOD;
    }

    return sum;
}