// The time complexity of DFS using an adjacency list is O(V + E) because each vertex is visited once and every edge is traversed once. The space complexity is O(V) due to the visited array, recursion stack in the worst case (when the graph forms a linear chain), and the output list storing all vertices.
// ✅ 1️⃣ DFS (Depth First Search)
// 🔹 Easy Definition:
// DFS is a graph traversal algorithm that explores as deep as possible in one direction before coming back (backtracking).
// 🔹 Simple Understanding:
// Go to a node
// Go to its first unvisited neighbor
// Keep going deeper
// When no more nodes left → backtrack
// 🔹 Uses:
// Recursion or Stack
// Think of it like exploring a maze deeply first
// 🔹 Interview One-Line Version:
// DFS explores a graph by going deep into one branch before exploring other branches

class Solution {
  private:
    void dfs(int node,vector<vector<int>> &adj,int vis[],vector<int> &ls){
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }  
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        int vis[n]={0};
        int start=0;
        vector<int> ls;
        dfs(start,adj,vis,ls);
        return ls;
    }
};