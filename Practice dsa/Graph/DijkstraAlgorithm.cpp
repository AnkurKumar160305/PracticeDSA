class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(V);
        //{node,adjnode,wt}
        vector<int> dist(V, INT_MAX);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(d>dist[node]){
                continue;
            }
            for(auto it:adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                if (dist[node] + wt < dist[adjNode]){
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
            
        }
        
        return dist;
        
    }
};