#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int>g_roadways[410];
vector<int>g_airlanes[410];
int ar[410][410];


struct edge {
    int a, b, cost;
};

int k, m, v;
vector<edge> e;
const int INF = 100000000;
bool cycle = false;
void solve() {
    vector<int> d (k, INF);
    d[v] = 0;
    vector<int> p (k, -1);
    int x;
    for (int i=0; i<k; ++i) {
        x = -1;
        for (int j=0; j<k * k; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        cycle = false;
    else {
        int y = x;
        for (int i=0; i<k; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur]) {
            path.push_back (cur);
            if (cur == y && path.size() > 1)  break;
        }
        reverse (path.begin(), path.end());

        cout << "YES" << endl;
        cout << path.size() << endl;
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] + 1 << ' ';
        cout << endl;
        cycle = true;
    }
}

int main(){
    cin >> k;
    vector<int> d(k, INF);
    for (int i = 0; i < k; i ++){
        for (int j = 0; j < k; j ++){
            edge cur;
            cin >> cur.cost;
            cur.a = i; cur.b = j;
            e.push_back(cur);
        }
    }
    for (int i = 0; i < k; i ++){
        v = i;
        solve();
        if (cycle == true) break;
    }
    if (cycle == false) cout << "NO" << endl;
}