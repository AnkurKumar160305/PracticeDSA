#include<bits/stdc++.h>

//DFS+Recursion stack
bool checkCycle(int i,unordered_map<int,bool>& vis,unordered_map<int,bool>& dfsVis,
unordered_map<int,vector<int>>& adj){
  vis[i]=true;
  dfsVis[i]=true;
  for(auto it:adj[i]){
    if(!vis[it]){
      bool cycledetected=checkCycle(it,vis,dfsVis,adj);
      if(cycledetected){
        return true;
      }
    }else if(dfsVis[it]==true){
      return true;
    }
  }
  dfsVis[i]=false;
  return false;
}



int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  unordered_map<int,vector<int>> adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  unordered_map<int,bool> vis;
  unordered_map<int,bool> dfsVis;

  for(int i=1;i<=n;i++){
    if(!vis[i]){
      bool ans=checkCycle(i,vis,dfsVis,adj);
      if(ans==true){
        return true;
      }
    }
  }
  return false;
}


//Kahn algo+BFS
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>> adj;
          for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
          }
        vector<int> indegree(V,0);
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int index=0;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            index++;
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return index!=V;
    }
};