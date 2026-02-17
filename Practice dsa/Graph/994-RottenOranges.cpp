class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int time=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty() && fresh>0){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                        grid[nrow][ncol]=2;
                        fresh--;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        if(fresh>0){
            return -1;
        }
        return time;
    }
};


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                    if(grid[i][j]==1){
                        fresh++;
                    }
                }
            }
        }
        int maxi=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            maxi=max(maxi,time);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol]!=2 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }

        if(cnt!=fresh){
            return -1;
        }
        return maxi;
    }
};