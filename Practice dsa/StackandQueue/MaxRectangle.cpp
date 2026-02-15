class Solution {
  private:
    vector<int> nextSmallerElement(vector<int> heights,int n){
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
    vector<int> prevSmallerElement(vector<int> heights,int n){
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
    int largestRectangleArea(vector<int> heights,int n) {
        // int n=heights.size();

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
  public:
    int maxArea(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        // area for first row
        int area=largestRectangleArea(mat[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //row update by adding previous row element value to current row
                //check if base is not equal to zero
                if(mat[i][j]!=0){
                    mat[i][j]=mat[i][j]+mat[i-1][j];
                }else{
                    mat[i][j]=0;
                }
            }
            //Entire row is updated now
            area=max(area,largestRectangleArea(mat[i],m));
        }
        return area;
    }
};