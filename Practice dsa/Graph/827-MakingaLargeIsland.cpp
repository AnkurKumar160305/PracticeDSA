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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        
        DSU ds(n*n);

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        int nodeNo=row*n+col;
                        int adjNodeNo=nrow*n+ncol;
                        ds.Union(nodeNo,adjNodeNo);
                    }
                }
            }
        }

        int maxi=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                set<int> component;
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        component.insert(ds.findParent(nrow*n+ncol));
                    }
                }
                int sizeTotal=0;
                for(auto it:component){
                    sizeTotal+=ds.size[it];
                }
                maxi=max(maxi,sizeTotal+1);
            }
        }

        for(int cellno=0;cellno<n*n;cellno++){
            maxi=max(maxi,ds.size[ds.findParent(cellno)]);
        }

        return maxi;
    }
};