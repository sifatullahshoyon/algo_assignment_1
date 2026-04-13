#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> graph(n);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        bool found = false;

        if (x == y) {
            found = true;
        } else {
            for (int j = 0; j < graph[x].size(); j++) {
                if (graph[x][j] == y) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}