class Solution {
    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int findParent(int node) {
            if (parent[node] == node)
                return node;

            return parent[node] = findParent(parent[node]);
        }

        void Union(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if (pu == pv)
                return;

            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    };

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {

        DSU dsu(n * m);

        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> ans;

        int cnt = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (auto &it : A) {

            int row = it[0];
            int col = it[1];

            // Already land
            if (vis[row][col]) {
                ans.push_back(cnt);
                continue;
            }

            // Make new land
            vis[row][col] = 1;
            cnt++;

            int nodeNo = row * m + col;

            // Check all 4 neighbours
            for (int i = 0; i < 4; i++) {

                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    vis[newRow][newCol]) {

                    int adjNode = newRow * m + newCol;

                    if (dsu.findParent(nodeNo) != dsu.findParent(adjNode)) {
                        dsu.Union(nodeNo, adjNode);
                        cnt--;
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};