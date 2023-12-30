#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> graph[100008];
bool used[100008];

int main(){
    int n;
    cin >> n;
    // int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(i != j){
                graph[i].push_back({j, x});
            }
        }
    }
    int ans = 0;

    priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>>> q;
    q.push({0, 1}); //first element
    while(!q.empty()){
        pair <int, int> p = q.top();
        q.pop();
        int mst = p.first, v = p.second;
        if(used[v]) continue;

        used[v] = true;
        ans += mst; //weight

        for(pair <int, int> i : graph[v]){
            int u = i.first, length = i.second;
            if(!used[u]){
                q.push({length, u});
            }
        }
    }
    cout << ans << endl;
}