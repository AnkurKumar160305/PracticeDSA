class Solution {

    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int& maxarea){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        int cnt=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    cnt++;
                    q.push({nrow,ncol});
                }
            }
            maxarea=max(maxarea,cnt);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    bfs(i,j,vis,grid,maxarea);
                }
            }
        }

        return maxarea;
    }
};