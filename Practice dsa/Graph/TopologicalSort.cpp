//used in DAG directed acyclic graph 
//Steps
//1 first we calculate indegree of all the vertices
//2 BFS queue -> the nodes which have indegree 0 will be pushed into the queue and now i will traverse adjacent elements of the node and decrease their indegree by 1 and if any of the adjacent elemnt has indegree 0 then push it into the queue and also store the node in the ans vector if the indegree of the node is 0 then push it into the queue and also store the node in the ans vector


class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int e=edges.size();
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
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
        
        vector<int> ans;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return ans;
        
    }
};


#include <bits/stdc++.h>

void topo(int node,vector<bool>& vis,stack<int>& s,vector<vector<int>>& adj){
    vis[node]=1;

    for(auto i:adj[node]){
        if(!vis[i]){
            topo(i,vis,s,adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool> vis(v, false);
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,vis,s,adj);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;

}