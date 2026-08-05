class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({grid[0][0], 0, 0});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (vis[r][c]) continue;
            vis[r][c] = 1;

            if (r == n - 1 && c == n - 1)
                return time;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !vis[nr][nc]) {

                    pq.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1;
    }
};