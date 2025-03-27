#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> indegree(n, 0), topo;
    queue<int> q;

    for (auto u : graph)
    {
        for (auto v : u)
        {
            indegree[v]++; // Adding the indegree
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!indegree[i]) 
            q.push(i); // Pushing the nodes to the queue with indegree 0
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (auto v : graph[u])
        {
            indegree[v]--;
            if (!indegree[v])
                q.push(v);
        }
    }

    return topo;
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