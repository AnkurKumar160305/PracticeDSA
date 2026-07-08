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


//BFS
class Solution {

    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& image,int color,
    int temp){
        vis[row][col]=1;
        image[row][col]=color;

        queue<pair<int,int>> q;
        q.push({row,col});

        int n=image.size();
        int m=image[0].size();


        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
                image[nrow][ncol]==temp){
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int temp=image[sr][sc];
        vector<vector<int>> vis(n,vector<int> (m,0));
        bfs(sr,sc,vis,image,color,temp);

        return image;
    }
};