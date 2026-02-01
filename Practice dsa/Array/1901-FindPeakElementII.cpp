class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int low=0,high=c-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxRow=0;
            for(int i=0;i<r;i++){
                if(mat[i][mid]>mat[maxRow][mid]){
                    maxRow=i;
                }
            }
            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < c) ? mat[maxRow][mid + 1] : -1;

            if(mat[maxRow][mid]>left && mat[maxRow][mid]>right){
                return {maxRow,mid};
            }else if(mat[maxRow][mid]<right){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return {-1,-1};

    }
};