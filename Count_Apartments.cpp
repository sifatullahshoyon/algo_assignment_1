#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool visited[1005][1005];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny] && grid[nx][ny] == '.') {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}