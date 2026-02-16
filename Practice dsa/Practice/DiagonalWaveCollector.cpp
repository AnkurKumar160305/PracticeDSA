vector<vector<int>> diagonalWaveCollector(vector<vector<int>>& grid) {
    // add your code here
   int n=grid.size();
   int m=grid[0].size();
   vector<vector<int>> res(n+m-1);
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        res[i+j].push_back(grid[i][j]);
    }
   }
   return res;
}