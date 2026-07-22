class Solution {
    void dfs(int node,int parent,int& timer,vector<int>& disc,vector<int>& low,
    vector<bool>& AP,unordered_map<int,vector<int>>& adj,unordered_map<int,bool>& vis){
        vis[node]=true;
        disc[node]=low[node]=timer++;
        int child=0;
        for(auto nbr:adj[node]){
            if(nbr==parent){
                continue;
            }
            if(!vis[nbr]){
                dfs(nbr,node,timer,disc,low,AP,adj,vis);
                low[node]=min(low[node],low[nbr]);
                
                //check Articulation Point  or not
                if(low[nbr]>=disc[node] && parent!=-1){
                    AP[node]=true;
                }
                child++;
            }else{
                //Back edge
                low[node]=min(low[node],disc[nbr]);
            }
        }
        //checking if starting node(0) have more than one child if it is true then it is also
        //AP
        if(parent==-1 && child>1){
            AP[node]=true;
        }
        
    }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
    
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
    
        int timer=0;
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        int parent=-1;
        unordered_map<int,bool> vis;
    
        vector<bool> AP(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,parent,timer,disc,low,AP,adj,vis);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(AP[i]!=false){
                ans.push_back(i);
            }
        }
        
        if(ans.empty()) return {-1}; 
        
        return ans;
    }
};