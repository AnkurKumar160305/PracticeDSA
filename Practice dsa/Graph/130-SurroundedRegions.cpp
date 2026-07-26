class Solution {
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();

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
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && (i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O'){
                    bfs(i,j,vis,board);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                    vis[i][j]=1;
                }
            }
        }


    }
};


