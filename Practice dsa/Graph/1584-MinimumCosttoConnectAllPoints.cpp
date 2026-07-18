class DSU{
        public:
        vector<int> parent,size;
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
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
            
            if(size[pv]>size[pu]){
                parent[pu]=pv;
                size[pv]+=size[pu];
            }else{
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
            
        }
};

class Solution {

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DSU dsu(n);

        vector<vector<int>> edges;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(points[j][1]-points[i][1])+abs(points[j][0]-points[i][0]);
                edges.push_back({wt,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int sum=0;
        for(auto i:edges){
            int u=i[1];
            int v=i[2];
            int wt=i[0];
            if(dsu.findParent(u)!=dsu.findParent(v)){
                sum+=wt;
                dsu.Union(u,v);
            }
        }
        return sum;
    }
};