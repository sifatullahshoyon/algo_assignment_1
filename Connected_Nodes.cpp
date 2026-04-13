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
        graph[b].push_back(a); // undirected
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (graph[x].size() == 0) {
            cout << -1 << endl;
            continue;
        }

        sort(graph[x].begin(), graph[x].end(), greater<int>());

        for (int j = 0; j < graph[x].size(); j++) {
            cout << graph[x][j] << " ";
        }
        cout << endl;
    }

    return 0;
}