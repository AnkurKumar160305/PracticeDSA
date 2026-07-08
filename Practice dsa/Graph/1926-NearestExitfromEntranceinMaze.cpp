class Solution {

    int bfs(int row,int col,vector<vector<char>>& maze,vector<vector<int>>& vis){
        int n=maze.size();
        int m=maze[0].size();
        vis[row][col]=1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{row,col},0});

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dist=q.front().second;
            q.pop();

            if((r==0 || r==n-1 || c==0 || c==m-1) && !(r==row && c==col)){
                return dist;
            }
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && maze[nrow][ncol]=='.'){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }

        return -1;
    }


public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int row=entrance[0];
        int col=entrance[1];
        int ans=bfs(row,col,maze,vis);
        return ans;
    }
};