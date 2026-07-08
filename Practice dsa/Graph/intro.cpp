#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    // Adjacency Matrix
    int matrix[n+1][n+1] = {0};

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        matrix[u][v] = 1;
        matrix[v][u] = 1;   // Undirected graph
    }

    // Adjacency List
    vector<int> list[n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        list[u].push_back(v);
        list[v].push_back(u);
    }

    return 0;
}