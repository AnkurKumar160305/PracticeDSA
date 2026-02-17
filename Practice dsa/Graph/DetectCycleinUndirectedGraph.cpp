class Solution {
    bool detect(int src,vector<int> adj[],vector<int>& vis){
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjNode:adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({adjNode,node});
                }else if(parent!=adjNode){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
        
    }
};