class Solution {

    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});

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
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    bfs(i,j,vis,grid);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vis[i][j]=1;
                    cnt++;
                }
            }
        }


        return cnt;
    }
};