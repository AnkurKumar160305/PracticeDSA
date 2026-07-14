class Solution {
    void dfs(int node,vector<vector<int>>& adj,vector<int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};


//Optimal by DSU
class Solution {
    class DSU{
        public:
        vector<int> parent,size;
        DSU(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findParent(int u){
            if(u==parent[u]){
                return u;
            }
            return parent[u]=findParent(parent[u]);
        }

        void Union(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);

            if(pu == pv) return;
            
            if(size[pv]>size[pu]){
                parent[pu]=parent[pv];
                size[pv]+=size[pu];
            }else{
                parent[pv]=parent[pu];
                size[pu]+=size[pv];
            }
        }

    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        DSU ds(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                    ds.Union(i,j);
                }
            }
        }

        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(ds.findParent(i));
        }
        return s.size();

    }
};