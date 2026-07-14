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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU ds(n);

        for(auto it:edges){
            ds.Union(it[0],it[1]);
        }
        return ds.findParent(source)==ds.findParent(destination);
    }
};