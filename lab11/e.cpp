#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
vector<int> answer;
int cnt;
int p[200005];
int rk[200005];

void init_dsu() {
    for (int i = 0; i < 200005; i++) {
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
        return true;
    } else {
        if (rk[ra] < rk[rb]) {
            p[ra] = rb;
        } else if (rk[rb] < rk[ra]) {
            p[rb] = ra;
        } else {
            p[ra] = rb;
            rk[rb]++;
        }

        return false;
    }
}
int main(){
    int n, m;
    cnt = 0;
    init_dsu();
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = n; i > 1; i --){
        cnt++;
        for (int j = 0; j < g[i].size(); j ++){
            if (g[i][j] > i && get_root(i) != get_root(g[i][j])){
                cnt--;
                merge(i, g[i][j]);
            }
        }
        answer.push_back(cnt);
    }

    reverse(answer.begin(), answer.end());
    for(int i = 0; i < answer.size();i++){
        cout << answer[i] << endl;
    }
    cout << 0 << endl;

}
