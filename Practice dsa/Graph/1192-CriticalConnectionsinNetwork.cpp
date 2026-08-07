class Solution {

    void dfs(int node,int parent,int &timer,vector<int>& disc,vector<int>& low,vector<vector<int>>& result,vector<vector<int>>& adj,vector<bool>& vis){
        vis[node]=true;
        disc[node]=low[node]=timer++;

        for(auto nbr:adj[node]){
            if(nbr==parent) continue;
            if(!vis[nbr]){
                dfs(nbr,node,timer,disc,low,result,adj,vis);
                low[node]=min(low[node],low[nbr]);

                //check edges is bridge or not
                if(low[nbr]>disc[node]){
                    result.push_back({node,nbr});
                }

            }else{
                //node is already visited and not a parent
                //Back edge
                low[node]=min(low[node],disc[nbr]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }   

        int timer=0;
        int parent=-1;
        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        vector<bool> vis(n,false);

        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,parent,timer,disc,low,result,adj,vis);
            }
        }

        return result;

    }
};