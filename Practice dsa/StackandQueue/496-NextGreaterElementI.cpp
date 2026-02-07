class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ans;
        stack<int> st;

        for(int num:nums2){
            while(!st.empty() && num>st.top()){
                ans[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()){
            ans[st.top()]=-1;
            st.pop();
        }
        vector<int>res;
        for(auto num:nums1){
            res.push_back(ans[num]);
        }
        return res;
    }
};