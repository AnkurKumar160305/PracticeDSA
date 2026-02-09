class Solution {

  public:
    vector<int> downwardDiagonal(int N, vector<vector<int>> A) {
        // Your code goes here
        vector<int> ans;
        ans.push_back(A[0][0]);
        for(int c=1;c<N;c++){
            int i = 0, j = c;
            while (i < N && j >=0) {
                ans.push_back(A[i][j]);
                i++;
                j--;
            }
        }
        
        for(int r=1;r<N;r++){
            int i = r, j = N-1;
            while (i < N && j >=0) {
                ans.push_back(A[i][j]);
                i++;
                j--;
            }    
        }
        return ans;
    }
};