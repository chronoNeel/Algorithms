// There is an undirected graph with n nodes. There is also an edges array,
// where edges[i] = [a, b] means that there is an edge between node a and node b in the graph.
// The nodes are numbered from 0 to n - 1.
// Return the total number of connected components in that graph.

#include <bits/stdc++.h>

using namespace std;

// Recursive DfS

void dfs(vector<vector<int>> &edges, vector<bool> &vis, int u)
{
    vis[u] = 1;
    for (auto v : edges[u])
    {
        if (!vis[v])
        {
            dfs(edges, vis, v);
        }
    }
}

// DFS using stack

void dfsStack(vector<vector<int>> &edges, vector<bool> &vis, int u)
{
    stack<int> st;
    st.push(u);
    vis[u] = 1;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (int i = 0; i < edges[node].size(); i++)
        {
            int v = edges[node][i];
            if (!vis[v])
            {
                st.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main()
{
    int n, V;
    cin >> n >> V;
    vector<vector<int>> edges(n);
    for (int i = 0; i < V; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int connected = 0;
    vector<bool> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            connected++;
            dfsStack(edges, vis, i);
        }
    }

    cout << "Number of connected components: " << connected <
}

/*
5
4
0 1
1 2
2 3
3 4


5
2
0 1
3 4

4 0
*/