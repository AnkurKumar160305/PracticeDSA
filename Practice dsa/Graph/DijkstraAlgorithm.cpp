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


//OR
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,vector<pair<int,int>>> adj;

    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(vertices,INT_MAX);

    set<pair<int,int>> s;
    //{dist,node}

    dist[source]=0;

    s.insert({0,source});

    while(!s.empty()){
        auto top=*(s.begin());

        int nodeDistance=top.first;
        int topNode=top.second;

        s.erase(s.begin());

        for(auto i:adj[topNode]){
            if(nodeDistance+i.second<dist[i.first]){
                auto record=s.find({dist[i.first],i.first});
                //if record exist remove it
                if(record!=s.end()){
                    s.erase(record);
                }

                //update distance
                dist[i.first]=nodeDistance+i.second;

                s.insert({dist[i.first],i.first});
            }
        }
    }

    return dist;
}
