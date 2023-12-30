#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int n, m;

void DFS(char** matrix, int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] == '0') return;
	matrix[i][j] = '0';
	DFS(matrix, i + 1, j);
	DFS(matrix, i - 1, j);
	DFS(matrix, i, j + 1);
	DFS(matrix, i, j - 1);
}

int main() {
    int cnt = 0;
	cin >> n >> m;
	char** matrix = new char* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new char[m];
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == '1') {
				DFS(matrix, i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
// int numIslands(vector<vector<char>>& grid) {
//     int m = grid.size(), n = m ? grid[0].size() : 0;
//     int count = 0;
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (grid[i][j] == '1') {
//                 dfs(grid, i, j);
//                 count++;
//             }
//         }
//     }
//     return count;
// }
// void dfs(vector<vector<char>>& grid, int i, int j) {
//     int m = grid.size(), n = grid[0].size();
//     if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
//         return;
//     }
//     grid[i][j] = '0';
//     dfs(grid, i - 1, j);
//     dfs(grid, i + 1, j);
//     dfs(grid, i, j - 1);
//     dfs(grid, i, j + 1);
// }

