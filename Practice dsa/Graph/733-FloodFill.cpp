class Solution {
    void dfs(int sr,int sc,int color,vector<vector<int>>& vis,vector<vector<int>>& image,int temp){
        int n=image.size();
        int m=image[0].size();
        vis[sr][sc]=1;
        image[sr][sc]=color;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == temp && !vis[nrow][ncol]){
                dfs(nrow,ncol,color,vis,image,temp);
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int temp=image[sr][sc];
        dfs(sr,sc,color,vis,image,temp);
        return image;
    }
};