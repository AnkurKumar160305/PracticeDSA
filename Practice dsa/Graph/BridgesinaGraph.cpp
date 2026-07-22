//Tarjan's Algorithm -> 
// disc[node] = When was this node first visited?
// low[node] = What's the earliest-discovered node this node (or its subtree) can reach using tree edges and at most one back edge?
// If low[child] > disc[parent], the child's subtree has no alternate path to the parent or any ancestor. Therefore, the edge (parent, child) is a bridge.

#include<bits/stdc++.h>

void dfs(int node,int parent,int& timer,vector<int>& disc,vector<int>& low,
vector<vector<int>>& result,unordered_map<int,vector<int>>& adj,unordered_map<int,bool>& vis){
    vis[node]=true;
    disc[node]=low[node]=timer++;

    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            low[node]=min(low[node],low[nbr]);

            //check edge is a bridge or not
            if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }else{
            //Back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,vector<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    int timer=0;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    int parent=-1;
    unordered_map<int,bool> vis;

    vector<vector<int>> result;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }
    return result;
}