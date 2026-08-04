class Solution {
    class DSU{
        public:
        vector<int> parent,size;
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int findParent(int u){
            if(parent[u]==u){
                return u;
            }
            return parent[u]=findParent(parent[u]);
        }

        void Union(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);

            if(pu==pv) return;

            if(size[pu]>size[pv]){
                parent[pv]=parent[pu];
                size[pu]+=size[pv];
            }else{
                parent[pu]=parent[pv];
                size[pv]+=size[pu];
            }
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);

        if(connections.size()<n-1) return -1;

        for(auto i:connections){
            ds.Union(i[0],i[1]);
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i){
                cnt++;
            }
        }

        return cnt-1;
    }
};