#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	vector<vector<int>> adj(n+1);
	for(auto i:edges){
		int u=i.first;
		int v=i.second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> vis(n+1, false);
    vector<int> parent(n+1, -1);

	queue<int> q;
	q.push(s);
	vis[s]=true;

	while(!q.empty()){
		int top=q.front();
		q.pop();
		for(auto i:adj[top]){
			if(!vis[i]){
				vis[i]=1;
				parent[i]=top;
				q.push(i);
			}
		}
	}
	if(!vis[t]) return {};

	vector<int> ans;
	int curr=t;

	while(curr!=-1){
		ans.push_back(curr);
		curr=parent[curr];
	}
	reverse(ans.begin(),ans.end());
	return ans;
	
}
