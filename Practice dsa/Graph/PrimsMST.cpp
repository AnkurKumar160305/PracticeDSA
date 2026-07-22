#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(
    int n, int m,
    vector<pair<pair<int, int>, int>> &g)
{
    // Step 1: Create adjacency list
    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto &edge : g)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int wt = edge.second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // Step 2: Data Structures
    vector<int> key(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);

    // Min Heap -> {weight, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Start from node 1
    key[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;

        for (auto &it : adj[node])
        {
            int neighbour = it.first;
            int weight = it.second;

            if (!visited[neighbour] && weight < key[neighbour])
            {
                key[neighbour] = weight;
                parent[neighbour] = node;
                pq.push({weight, neighbour});
            }
        }
    }

    // Step 3: Store MST edges
    vector<pair<pair<int, int>, int>> ans;

    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}