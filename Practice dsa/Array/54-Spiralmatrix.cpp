class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int strow=0,endrow=r - 1;
        int stcol=0,endcol=c - 1;

        vector<int> ans;
        while(strow<=endrow && stcol<=endcol){
           for(int i=stcol;i<=endcol;i++){
                ans.push_back(matrix[strow][i]);
           }
           for(int i=strow+1;i<=endrow;i++){
                ans.push_back(matrix[i][endcol]);
           }
           for(int i=endcol-1;i>=stcol;i--){
                if(strow==endrow){
                    break;
                }
                ans.push_back(matrix[endrow][i]);
           }
           for(int i=endrow-1;i>strow;i--){
                if(stcol==endcol){
                    break;
                }
                ans.push_back(matrix[i][stcol]);
           }
           strow++;
           stcol++;
           endrow--;
           endcol--;
        }

        return ans;
    }
};