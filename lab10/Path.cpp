#include <bits/stdc++.h>
using namespace std;
const int MAXX = 100005;
vector<int> g[MAXX];
bool used[MAXX];
vector<int> p(MAXX);
vector<int> d(MAXX);
int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            int x; cin >> x;
            if(x == 1) {
                g[i].push_back(j);
            }
        }
    }
    int start, end;
    cin >> start >> end;
    queue<int> q;
    q.push(start);
    used[start] = true;
    p[start] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    if(used[end]) cout << d[end] << endl;
    else cout << -1 << endl;
        // for(int i = 1; i <= n; i++){
        //     cout << d[i] << " ";
        // }
        // cout << endl;
        // for(int i = 1; i <= n; i++){
        //     cout << p[i] << " ";
        // }
}