class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<times.size();i++){
            int src=times[i][0];
            int dest=times[i][1];
            int time=times[i][2];
            adj[src].push_back({dest,time});
        }

        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(d>dist[node]){
                continue;
            }
            for(auto i:adj[node]){
                int adjNode=i.first;
                int t=i.second;

                if(dist[node]+t<dist[adjNode]){
                    dist[adjNode]=dist[node]+t;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;

    }
};



//using bfs
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        // Build graph
        for(auto i : times) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].push_back({v, wt});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);

        queue<int> q;

        dist[k] = 0;
        q.push(k);

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                // Relaxation
                if(dist[node] + wt < dist[adjNode]) {

                    dist[adjNode] = dist[node] + wt;

                    q.push(adjNode);
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};