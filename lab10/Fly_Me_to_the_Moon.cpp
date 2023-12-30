#include <bits/stdc++.h>
using namespace std;
int n, m;
vector < vector <int>> g;
vector <int> color;

bool cycle(int vertex, pair <int, int> e){
    color[vertex] = 1;
    for(int i = 0; i < g[vertex].size(); i++){
        if(vertex == e.first && g[vertex][i] == e.second){
            continue;
        }
        if(color[g[vertex][i]] == 1){
            return true;
        }
        if(color[g[vertex][i]] == 0){
           if(cycle(g[vertex][i], e)){
            return true;
           }
        }
    }
    color[vertex] = 2;
    return false;
}
int main(){
    cin >> n >> m;
    g.resize(n);
    color.resize(n);
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < g[i].size(); j++){
            bool noCycle = true;
            for(int k = 0; k < n; k++){
                if(cycle(k, {i, g[i][j]})){
                    noCycle = false;
                    break;
                }
            }
            if(noCycle){
                cout << "YES";
                return 0;
            }
        color.assign(n, 0);
        }
    }
    cout << "NO";
    return 0;
}