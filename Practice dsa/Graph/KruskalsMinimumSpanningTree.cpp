// Minimum Spanning Tree - Kruskal's Algorithm

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
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(),compare);
        DSU dsu(V);
        
        int sum=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(dsu.findParent(u)!=dsu.findParent(v)){
                sum+=w;
                dsu.Union(u,v);
            }
        }
        
        return sum;
        
        
    }
};



//By rank method
#include<bits/stdc++.h>

class DSU{
  public:
  vector<int> parent;
  vector<int> rank;
  DSU(int n){
    parent.resize(n);
    rank.resize(n);
    for(int i=0;i<n;i++){
      parent[i]=i;
      rank[i]=0;
    }
  }

  int findParent(int node){
    if(parent[node]==node){
      return node;
    }
    return parent[node]=findParent(parent[node]);
  }

  void findUnion(int u,int v){
    int pu=findParent(u);
    int pv=findParent(v);

    if(pu==pv){
      return;
    }

    if(rank[pv]==rank[pu]){
      parent[pu]=pv;
      rank[pv]++;
    }else if(rank[pv]>rank[pu]){
      parent[pu]=pv;
    }else{
      parent[pv]=pu;
    }
  }
};

static bool compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  DSU dsu(n);
  int sum=0;
  sort(edges.begin(),edges.end(),compare);
  for(int i=0;i<edges.size();i++){
    int u=edges[i][0];
    int v=edges[i][1];
    int w=edges[i][2];
    if(dsu.findParent(u)!=dsu.findParent(v)){
      sum+=w;
      dsu.findUnion(u,v);
    }
  }
  return sum;
}