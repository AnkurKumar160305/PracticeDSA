class Solution {
public:
    int dfs(vector<vector<int>>&stones,int index,vector<bool>&visited,int&n){
        visited[index]=true;
        int result=0;
        for(int i=0;i<n;i++)
            if(!visited[i] && (stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                result +=(dfs(stones,i,visited,n) + 1);
        return result;
    }
    int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
        vector<bool>visited(n,0);
        int result=0;
        for(int i=0;i<n;i++){
            if(visited[i]){continue;}
            result+=dfs(stones,i,visited,n);
        }
        return result;
    }
};


//OR

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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        DSU ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    ds.Union(i,j);
                }
            }
        }
        int components=0;
        for(auto i=0;i<n;i++){
            if(ds.findParent(i)==i){
                components++;
            }
        }

        return n-components;
    }
};