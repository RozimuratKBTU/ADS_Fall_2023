#include <bits/stdc++.h>
using namespace std;
int p[100000];
int rk[100000];

void init_dsu() {
    for (int i = 0; i < 100000; i++) {
        p[i] = i;
        rk[i] = 1;
    }
}

int get_root(int v) {
    if (p[v] == v) {
        return v;
    } else {
        return p[v] = get_root(p[v]);
    }
}

bool merge(int a, int b) {
    int ra = get_root(a), rb = get_root(b);

    if (ra == rb) {
        return false;
    } else {
        if (rk[ra] < rk[rb]) {
            p[ra] = rb;
        } else if (rk[rb] < rk[ra]) {
            p[rb] = ra;
        } else {
            p[ra] = rb;
            rk[rb]++;
        }

        return true;
    }
}


vector<pair<int, pair<int,int>>> edges;
int main() {
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= m; i ++){
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        if (s == "big"){
            edges.push_back({c*x, {a, b}});
            edges.push_back({c*x, {b, a}});
        }
        else if (s == "small"){
            edges.push_back({c*y, {a, b}});
            edges.push_back({c*y, {b, a}});
        }
        else{
            edges.push_back({c * min(x, y), {b, a}});
            edges.push_back({c * min(x, y), {a, b}});
        }
    }

    sort(edges.begin(), edges.end());

    int mst_weight = 0;

    init_dsu();

    for (int i = 0; i < edges.size(); i ++){
        if (merge(edges[i].second.first, edges[i].second.second)){
            mst_weight += edges[i].first;
        }
    }
    cout << mst_weight << endl;
}