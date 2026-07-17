class NumArray {
    vector<int> seg;
    vector<int> nums;
    int n;
    void build(int node,int start,int end){
        if(start==end){
            seg[node]=nums[start];
            return;
        }
        int mid=start+(end-start)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        seg[node]=seg[2*node]+seg[2*node+1];
    }
    void updateTree(int node, int start, int end, int index, int val) {
        if(start==end){
            seg[node] = val;
            nums[index] = val;
            return;
        }
        int mid=start+(end-start)/2;
        if(index<=mid){
            updateTree(2*node,start,mid,index,val);
        }else{
            updateTree(2*node+1,mid+1,end,index,val);
        }
        seg[node]=seg[2*node]+seg[2*node+1];
    }
     int query(int node, int start, int end, int l, int r) {
        if (start >= l && end <= r) return seg[node];

        // Complete lie outside the query range
        if (end < l || start > r) return 0;

        // Partial overlap
        int mid = (start + end) / 2;

        return query(2 * node, start, mid, l, r)+query(2 * node+1, mid+1, end, l, r);
     }
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);
    }
    
    void update(int index, int val) {
        updateTree(1,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
         return query(1, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */