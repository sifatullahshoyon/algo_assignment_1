#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool visited[1005][1005];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y) {
    visited[x][y] = true;
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny] && grid[nx][ny] == '.') {
                cnt += dfs(nx, ny);
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;

    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == '.' && !visited[i][j]) {
                int rooms = dfs(i, j);
                ans.push_back(rooms);
            }
        }
    }

    // sort ascending
    sort(ans.begin(), ans.end());

    if (ans.size() == 0) {
        cout << 0 << endl;
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}