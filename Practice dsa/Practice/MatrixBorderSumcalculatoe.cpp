
int matrixBorderSum(vector<vector<int>>& grid) {
    // add your code here
    int r=grid.size();
    int sum=0;
    int c=grid[0].size();
    if(r==1){
        for (int j = 0; j < c; j++){
            sum += grid[0][j];
        }
        return sum;
    }
    if (c == 1) {
        for (int i = 0; i < r; i++){
            sum += grid[i][0];
        }
        return sum;
    }
    for(int i=0;i<r;i++){
        if(i==0){
            for(int j=0;j<c;j++){
                sum+=grid[i][j];
            }
        }else if(i==r-1){
            for(int j=0;j<c;j++){
                sum+=grid[i][j];
            }
        }else{
            sum+=grid[i][0]+grid[i][c-1];
        }
    }
    return sum;
}