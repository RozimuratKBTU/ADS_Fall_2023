#include <bits/stdc++.h>

using namespace std;

#define pb(i) push_back(i)
#define For(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()

template <typename T> void read(vector<T>& a) { For(i, a.size()) cin >> a[i]; }

const int p = 31, shift = 5e3 + 5, N = 1e4;
vector <int> power(N, 1);

void getPower() {
  for (int i = 1; i < N; ++i) {
    power[i] = power[i - 1] * p;
  }
}

vector<int> getHash(string s) {
  int n = s.length();
  vector<int> hash(n + 1);
  for (int i = 1; i <= n; i++) {
    hash[i] = hash[i - 1] + (s[i - 1] - 'a' + 1) * power[i - 1];
  }
  return hash;
}

void write() {
  int n;
  cin >> n;
  vector<string> a(n);
  read(a);
  vector<vector<int>> hashes(n);
  getPower();
  For(i, n) { hashes[i] = getHash(a[i]); }
  int l = 1, r = a[0].length();
  string remember = "";
  while (l < r) {
    int m = (l + r + 1) >> 1;
    bool ok = false;
    vector<vector<int>> b(n);
    for (int i = 0; i < n; i++) {
      int sz = a[i].length();
      bool found = false;
      for (int j = 0; j <= sz - m; j++) {
        int hash =
          (hashes[i][j + m] - hashes[i][j]) * power[(shift - j)];
        b[i].push_back(hash);
      }
    }
    for (int i = 1; i < n; i++) {
      sort(all(b[i]));
    }
    for (int i = 0; i < b[0].size(); i++) {
      int hash = b[0][i];
      bool found = true;
      for (int j = 1; j < n; j++) {
        if (!binary_search(b[j].begin(), b[j].end(), hash)) {
          found = false;
          break;
        }
      }
      if (found) {
        ok = true;
        remember = a[0].substr(i, m);
        break;
      }
    }
    if (ok) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << remember << endl;
}

int main() {
  int T;
  T = 1;
  // cin >> T;
  For(t, T) write();
  return 0;
}
