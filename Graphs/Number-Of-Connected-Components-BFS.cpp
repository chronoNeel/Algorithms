// There is an undirected graph with n nodes. There is also an edges array,
// where edges[i] = [a, b] means that there is an edge between node a and node b in the graph.
// The nodes are numbered from 0 to n - 1.
// Return the total number of connected components in that graph.

#include <bits/stdc++.h>

using namespace std;

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
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            connected++;
            q.push(i);
            vis[i] = 1;
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto v : edges[u])
            {
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }

    cout << "Number of connected components: " << connected;
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
