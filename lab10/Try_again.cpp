#include <bits/stdc++.h>
using namespace std;
vector<int> g[5005];
bool used[5005];
int d[5005];
int color[5005];
int n;

void bfs(int s) {
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    queue<int> q;
    q.push(s);
    d[s] = 0;
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                used[to] = true;
                q.push(to);
            }
        }
    }
}

int main() {
    int m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
    for (int t = 1; t <= q; t++) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            if (color[v] != 1) {
                bfs(v);
                color[v] = 1;
            }
        } else {
            if (d[v] == 1e9) {
                cout << -1 << endl;
            } else {
                cout << d[v] << endl;
            }
        }
    }
}