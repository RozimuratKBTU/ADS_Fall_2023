#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > g;
vector<int> p;
int n, q;
long long mincost = 0;

int dsu(int v) {
	if (v == p[v]) {
		return v;
	} else {
		return p[v] = dsu(p[v]);
	}
}

void dsuUnion(int a, int b) {
	a = dsu(a);
	b = dsu(b);
	p[a] = b;
}

int main() { 
	cin >> n >> q;
	p.resize(n);
	while (q--) {
		int l, r, c;
		cin >> l >> r >> c;
		l--; r--;
		g.push_back(make_pair(c, make_pair(l, r)));
	}
	
	sort(g.begin(), g.end());
	for (int i = 0; i < n; ++i)
		p[i] = i;
	
	for (int i = 0; i < g.size(); ++i) {
		int u = g[i].second.first;
		int v = g[i].second.second;
		int cost = g[i].first;

		for(int j = u + 1; j <= v; j++){
			if(dsu(u) != dsu(j)){
				dsuUnion(u, j);
				mincost += cost;
			}else{
				j = p[u];
			
			}
		}
	
	}

    cout << mincost << endl;

    return 0;
}