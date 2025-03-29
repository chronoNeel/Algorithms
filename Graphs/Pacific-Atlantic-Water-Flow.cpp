#include <bits/stdc++.h>

using namespace std;

void dfs (int x, int y, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
    visited[x][y] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int m = heights.size(), n = heights[0].size();

    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if (nx < 0 || ny < 0 || nx >= m || ny >= n || heights[nx][ny] < heights[x][y] || visited[nx][ny]) continue;
        dfs (nx, ny, heights, visited);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool> > pacific(m, vector<bool> (n, 0));
    vector<vector<bool> > atlantic(m, vector<bool> (n, 0));

    for (int i = 0; i < m; i ++) {
        dfs (i, 0, heights, pacific); // Left
        dfs (i, n - 1, heights, atlantic); // Right
    }

    for (int j = 0; j < n; j++) {
        dfs (0, j, heights, pacific); // Top
        dfs (m-1, j, heights, atlantic); // Down
    }

    vector<vector<int> > res;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                res.push_back ({i, j});
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<int> > heights{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};

    cout << "The cells where water can flow to both oceans are:\n";
    vector<vector<int>> res = pacificAtlantic (heights);

    for (auto v : res) {
        cout << v[0] << " " << v[1] << endl;
    }

    return 0;
}