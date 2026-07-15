class Solution {
    vector<int> dijkstra(int src,int n,vector<vector<int>>& edges){
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto i:edges){
            int n1=i[0];
            int n2=i[1];
            int d=i[2];
            adj[n1].push_back({n2,d});
            adj[n2].push_back({n1,d});
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
            for(auto i:adj[node]){
                int adjNode=i.first;
                int wt=i.second;
                if(dist[node]+wt<dist[adjNode]){
                    dist[adjNode]=dist[node]+wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        return dist;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = -1;
        int mini = INT_MAX;

        for(int src=0; src<n; src++){
            vector<int> dist = dijkstra(src,n,edges);

            int cnt = 0;
            for(int i=0;i<n;i++){
                if(dist[i] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= mini){
                mini = cnt;
                ans = src;   // larger index chosen automatically on tie
            }
        }

        return ans;
    }
};