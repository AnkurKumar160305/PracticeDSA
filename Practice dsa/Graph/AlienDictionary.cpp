#include<bits/stdc++.h>

class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        // code here
        
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
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        set<char> st;

        for(auto &word : words){
            for(char ch : word){
                st.insert(ch);
            }
        }
        
        int cnt = st.size();
        
        vector<vector<int>> adj(26);
        
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            if(s1.size() > s2.size() && s1.substr(0,s2.size())==s2)  return "";
            int len=min(s1.length(),s2.length());
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(26, adj);

        string ans;
        
        for(auto node : topo){
            char ch = node + 'a';
            if(st.count(ch)){
                ans += ch;
            }
        }
        
        if(ans.size() != st.size())
            return "";
        
        return ans;
        
    }
};