#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int parent) {
    // Assign color to the current node (opposite of parent's color)
    if (parent == -1 || color[parent] == 0) color[node] = 1;
    else color[node] = 0;

    // Traverse all neighbors
    for (auto v : graph[node]) {
        if (color[v] == -1) {  
            color[v] = (color[node] == 0) ? 1 : 0;  // Assign opposite color
            if (!dfs(graph, color, v, node)) return false;  
        } else if (color[v] == color[node]) {  // If neighbor has same color
            return false; 
        }
    }
    return true;
}


bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);  // Initialize all nodes as unvisited

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {  
            if (!dfs(graph, color, i, -1)) return false; 
        }
    }
    return true;
}

int main() {
    int n, E;
    cin >> n >> E;
    vector<vector<int>> graph(n);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isBipartite(graph)) {
        cout << "The graph is a bipartite graph";
    } else {
        cout << "The graph is not a bipartite graph";
    }

    return 0;
}


/*
4
5
0 1
0 3
0 2
1 2
2 3

4
4
0 1
1 2
2 3
3 0
*/