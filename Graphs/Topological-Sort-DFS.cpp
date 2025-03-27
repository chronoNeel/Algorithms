#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<int> &vis, vector<int> &res, int node)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : graph[u])
        {
            if (!vis[v]) dfs(graph, vis, res, v);
        }
    }

    res.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, 0), res;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(graph, vis, res, i);
        }
    }

    reverse(res.begin(), res.end());

    return res;
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

    vector<int> res = topologicalSort(graph);

    for (auto val : res)
        cout << val << " ";
    return 0;
}

/*
6
6
4 0
4 1
1 3
2 3
5 2
5 0

4
3
1 0
2 0
3 0
*/
