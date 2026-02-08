// min(max height on left, max height on right) - height[i]


class Solution {
public:
    int trap(vector<int>& height) {
        int s=0,e=height.size()-1;
        int leftMax=0,rightMax=0;
        int water=0;
        while(s<e){
            if(height[s]<=height[e]){
                if(height[s]>=leftMax){
                    leftMax=height[s];
                }else{
                    water+=leftMax-height[s];
                }
                s++;
            }else{
                if(height[e]>=rightMax){
                    rightMax=height[e];
                }else{
                    water+=rightMax-height[e];
                }
                e--;
            }
        }
        return water;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;   // stores indices
        int water = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();   // bottom
                st.pop();

                if (st.empty()) break;

                int left = st.top();
                int width = i - left - 1;
                int boundedHeight =min(height[left], height[i]) - height[mid];

                water += width * boundedHeight;
            }
            st.push(i);
        }
        return water;
    }
};
