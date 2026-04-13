#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int si, sj;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                si = i;
                sj = j;
            }
        }
    }

    queue<pair<int,int>> q;
    q.push({si, sj});

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[si][sj] = true;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    bool found = false;

    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        if (grid[x][y] == 'B') {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && grid[nx][ny] != '#') {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}