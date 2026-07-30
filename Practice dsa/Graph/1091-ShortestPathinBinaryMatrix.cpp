class Solution {
    int bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{row,col}});
        int drow[] = {-1,-1,-1,0,0,1,1,1};
        int dcol[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            if(r==n-1 && c==m-1) return d;
            
            for(int i=0;i<8;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({d+1,{nrow,ncol}});
                }
            }
        }

        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;

        return bfs(0,0,grid,vis);

    }
};
