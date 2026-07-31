class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();


        // effort[i][j] = minimum effort required to reach (i,j)
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        // {effort, {row, col}}
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>> pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1) return diff;

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m) {

                    int newEffort = max(diff,abs(heights[row][col] - heights[nrow][ncol]));

                    if (newEffort < effort[nrow][ncol]) {
                        effort[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }

        }

        return 0;
    }
};