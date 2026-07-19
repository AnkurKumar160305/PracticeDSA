// class Solution {
//   public:
//     vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
//         // code here
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         vector<int> dist(V,INT_MAX);
//         vector<vector<pair<int,int>>> adj(V);
        
//         for(auto i:edges){
//             int u=i[0];
//             int v=i[1];
//             int wt=i[2];
//             adj[u].push_back({v,wt});
//         }
        
//         dist[0]=0;
        
//         pq.push({0,0});
        
//         while(!pq.empty()){
//             int d=pq.top().first;
//             int node=pq.top().second;
//             pq.pop();
            
//             if(d>dist[node]){
//                 continue;
//             }
            
//             for(auto i:adj[node]){
//                 int w=i.second;
//                 int adjNode=i.first;
                
//                 if(w+dist[node]<dist[adjNode]){
//                     dist[adjNode]=w+dist[node];
//                     pq.push({dist[adjNode],adjNode});
//                 }
//             }
//         }
        
//         for(int i = 0; i < V; i++) {
//             if(dist[i] == INT_MAX){
//                 dist[i] = -1;
//             }
//         }
        
//         return dist;
        
//     }
// };





//OR

//DAG with negative weights

#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    unordered_map<int,vector<pair<int,int>>> adj;

    void addEdge(int u,int v,int wt){
        adj[u].push_back({v,wt});
    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }

    void dfs(int node,unordered_map<int,bool> &visited,stack<int> &st,unordered_map<int,vector<pair<int,int>>> &adj){
        visited[node]=true;

        for(auto i:adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,st,adj);
            }
        }

        st.push(node);
    }

    void getShortestPath(int src,stack<int> &st,vector<int> &dist){
        dist[src]=0;

        while(!st.empty()){
            int node=st.top();
            st.pop();

            if(dist[node]!=INT_MAX){
                for(auto i:adj[node]){
                    if(dist[node]+i.second<dist[i.first]){
                        dist[i.first]=dist[node]+i.second;
                    }
                }
            }
        }
    }
};


int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    int n=6;
    //topological sort
    unordered_map<int,bool> visited;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,st,g.adj);
        }
    }

    int src=1;
    vector<int> dist(n,INT_MAX);

    g.getShortestPath(src,st,dist);

    cout<<"Shortest distance from source "<<src<<" is: "<<endl;
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){
            cout<<"INF ";
        }
        else{
            cout<<dist[i]<<" ";
        }
    }

    return 0;

}