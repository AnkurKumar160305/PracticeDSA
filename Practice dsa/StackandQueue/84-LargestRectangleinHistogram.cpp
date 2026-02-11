class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<=n;i++){
            int curr=(i==n) ? 0 : heights[i]; 
            while(!st.empty() && curr<heights[st.top()]){
                int h=heights[st.top()];
                st.pop();
                int width=st.empty()?i:(i-st.top()-1);
                maxi=max(maxi,h*width);
            }
            st.push(i);
        }
        return maxi;
    }
};


class Solution {
    vector<int> nextSmallerElement(vector<int>& heights,int n){
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(vector<int>& heights,int n){
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int> next(n);
        next=nextSmallerElement(heights,n);

        vector<int> prev(n);
        prev=prevSmallerElement(heights,n);
        int area=0;

        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            area=max(area,l*b);
        }
        return area;
    }
};