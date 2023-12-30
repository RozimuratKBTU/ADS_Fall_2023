#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;
	int matrix[n+1][n+1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> matrix[i][j];
		}
	}
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << ((matrix[a][b] == 0 || matrix[a][c]  == 0|| matrix[b][c] == 0) ? "NO\n" : "YES\n");
	}

	return 0;
}