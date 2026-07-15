class Solution {
    class DSU{
        public:
        vector<int> parent,size;
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1,1);

            for(int i=1;i<=n;i++){
                parent[i]=i;
            }
        }

        int findParent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }

        void Union(int a,int b){
            int pa=findParent(a);
            int pb=findParent(b);

            if(pa==pb){
                return;
            }
            if(size[pa]>size[pb]){
                parent[pb]=pa;
                size[pa]+=size[pb];
            }else{
                parent[pa]=pb;
                size[pb]+=size[pa];
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int v=edges.size();

        DSU dsu(v);
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            if(dsu.findParent(u)==dsu.findParent(v)){
                ans.push_back(u);
                ans.push_back(v);
            }
            dsu.Union(u,v);
        }

        return ans;
    }
};