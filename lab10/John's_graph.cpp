#include <bits/stdc++.h>
using namespace std;
int m, n, a, b;
vector<vector<int> > g;
vector<bool> visited;
bool flag = false;

void dfs(int v) {
	if (v == b) {
		flag = true;
		return;
	}
	visited[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (!visited[to]) {
			dfs(to);
		}
	}
}
// bool dfs(int v) {
// 	if (v == b) return true;
// 	vis[v] = true;
// 	for (int i = 0; i < g[v].size(); i++) {
// 		int to = g[v][i];
// 		if (!vis[to]) {
// 			if (dfs(to)) return true;
// 		}
// 	}
// 	return false;
// }

int main() {

	cin >> m >> n;
	g.resize(m);
	visited.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> a >> b;
	a--; b--;
	dfs(a);
	if (flag == true) {
		cout << "YES";
	} else {
		cout << "NO";
	}


	return 0;
}