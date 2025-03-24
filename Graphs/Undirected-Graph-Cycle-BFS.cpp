// Given an undirected graph
// Check whether the graph contains any cycle or not
// The graph is represented in adjacency list

#include <bits/stdc++.h>

using namespace std;

bool detect (vector<vector<int>>& graph, vector<bool>& vis, int u) {
    queue<pair<int, int>> q;
    q.push({u, -1});
    vis[u] = 1;

    while (!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for (auto v : graph[node]) {
            if (!vis[v]) {
                q.push({v, node});
                vis[v] = 1;
            } else if (v != parent) {
                return true;
            }
        }
    }

    return false;
}

bool isCycle (vector<vector<int> >& graph) {
    int n = graph.size();
    vector<bool> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if(detect(graph, vis, i)) return true;
        }
    }

    return false;
}

int main()
{
    int n, E;
    cin >> n >> E;
    vector<vector<int> > edges(n);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    if (isCycle(edges)) cout << "The graph has cycle";
    else cout << "The graph does not have cycle";
}

/*
5
5
0 1
1 2
1 4
2 3
3 4

4
2
1 2
2 3
*/
