class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto i:roads){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);

        dist[0]=0;
        ways[0]=1;
        q.push({0,0});
        int mod=(int)(1e9+7);

        while(!q.empty()){
            long long ds=q.top().first;
            long long node=q.top().second;
            q.pop();

            if(ds > dist[node]) continue;

            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgewt=it.second;
                if(ds+edgewt<dist[adjNode]){
                    dist[adjNode]=ds+edgewt;
                    q.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }else if(ds+edgewt==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};