class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        while(!q.empty()){
            int steps=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();

            if(steps>k) continue;

            for(auto i:adj[node]){
                int adjNode=i.first;
                int wt=i.second;
                if(cost+wt<dist[adjNode]){
                    dist[adjNode]=cost+wt;
                    q.push({steps+1,{adjNode,dist[adjNode]}});
                }
            }
        }

        if(dist[dst]==INT_MAX) return -1;

        return dist[dst];
    }
};