// Given an undirected graph
// Check whether the graph contains any cycle or not
// The graph is represented in adjacency list

#include <bits/stdc++.h>

using namespace std;

bool detect (vector<vector<int>>& graph, vector<int>& vis, int u) {
    stack<pair<int,int>> st;
    st.push({u, -1});
    vis[u] = 1;

    while (!st.empty()) {
        auto [node, parent] = st.top();
        st.pop();

        for (auto v : graph[node]) {
            if (!vis[v]) {
                vis[v] = node;
                st.push({v, node});
            } else if (v != parent) {
                return true;
            }
        }
    }

    return false;
}


bool isCycle (vector<vector<int> >& graph) {
    int n = graph.size();
    vector<int> vis (n, 0);

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