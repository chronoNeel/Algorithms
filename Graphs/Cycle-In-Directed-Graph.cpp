#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int> &vis, vector<int> &path, int node)
{
    vis[node] = 1;
    path[node] = 1;

    for (auto v : graph[node])
    {
        if (!vis[v]) {
            if (dfs(graph, vis, path, v)) return true;
        } else if (path[v]) {
            return true;
        }
    }
    
    path[node] = 0;
    return false;
}

bool isCyclic(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, 0), path(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(graph, vis, path, i))
                return true;
        }
    }

    return false;
}

int main()
{
    int n, E;
    cin >> n >> E;
    vector<vector<int>> graph(n);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    if (isCyclic(graph))
        cout << "The graph is a cyclic graph";
    else
        cout << "The graph is not a cyclic graph";

    return 0;
}

/*
5 
3
3 0
4 2
1 2

4
4
0 1
1 2
2 3
3 3

9
10
0 1
1 3
3 4
4 5
5 3
1 2
2 6
6 8
2 9
9 8

*/