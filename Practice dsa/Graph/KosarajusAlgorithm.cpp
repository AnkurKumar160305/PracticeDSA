#include<bits/stdc++.h>

void topo(int node,vector<bool>& vis,stack<int>& s,
vector<vector<int>>& adj){
    vis[node]=1;

    for(auto i:adj[node]){
        if(!vis[i]){
            topo(i,vis,s,adj);
        }
    }
    s.push(node);
}

void dfs(int top,vector<bool>& vis,unordered_map<int,vector<int>>& transpose){
	vis[top]=1;

	for(auto i:transpose[top]){
		if(!vis[i]){
			dfs(i,vis,transpose);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	vector<vector<int>> adj(v);

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v1=edges[i][1];
        adj[u].push_back(v1);
    }
    vector<bool> vis(v, false);
    stack<int> s;

	//Topological sort
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,vis,s,adj);
        }
    }

	//create transpose graph
	unordered_map<int,vector<int>> transpose;
	for(int i=0;i<v;i++){
		vis[i]=0;
		for(auto nbr:adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	//Call DFS using above ordering
	int cnt=0;
	while(!s.empty()){
		int top=s.top();
		s.pop();
		if(!vis[top]){
			cnt++;
			dfs(top,vis,transpose);
		}
	}

	return cnt;

}