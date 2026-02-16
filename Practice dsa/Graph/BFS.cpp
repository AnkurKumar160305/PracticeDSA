// The time complexity of BFS using an adjacency list is O(V + E) because each vertex is visited once and every edge is traversed once. The space complexity is O(V) due to the visited array, the queue storing vertices in the worst case, and the output list.
// ✅ 2️⃣ BFS (Breadth First Search)
// 🔹 Easy Definition:
// BFS is a graph traversal algorithm that explores all neighbors at the current level before moving to the next level.
// 🔹 Simple Understanding:
// Start at a node
// Visit all its neighbors
// Then visit neighbors of neighbors
// Move level by level
// 🔹 Uses:
// Queue
// Think of it like spreading in circles
// 🔹 Interview One-Line Version:
// BFS explores a graph level by level using a queue.

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        int vis[n]={0};
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};