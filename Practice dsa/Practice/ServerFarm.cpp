void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& servers,int n,int m){
    vis[row][col]=1;
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int newrow=row+drow[i];
        int newcol=col+dcol[i];
        if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && !vis[newrow][newcol] && servers[newrow][newcol]=='.'){
            dfs(newrow,newcol,vis,servers,n,m);
        }
    }
}


int countContaminationClusters(vector<vector<char>>& servers, int n, int m)  {
    // add your code here'
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && servers[i][j]=='.'){
                dfs(i,j,vis,servers,n,m);
                cnt++;
            }
        }
    }
    return cnt;
}