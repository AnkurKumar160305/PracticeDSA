class Solution {
    bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& adj){
        color[node]=col;

        for(auto it:adj[node]){
            if(color[it]==-1){
                if(dfs(it,!col,color,adj)==false) return false;
            }else if(color[it]==color[node]){
                return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();

        vector<vector<int>> adj(v);

        for(int i=0;i<v;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<int> color(v,-1);

        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,adj)==false) return false;
            }
        }

        return true;
    }
};