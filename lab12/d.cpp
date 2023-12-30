#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, long long>>> g;
bool bfs(long long pred, int k){
    queue<int> q;
    vector<bool> vis(k);
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == k - 1)
             return true;
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i].first;
            long long cost = g[v][i].second;
            if(!vis[to] && pred >= cost){
                vis[to] = true;
                q.push(to);
            }
        }
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    g.resize(k);
    vector<pair<long long, long long> > coords;
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        coords.push_back(make_pair(x, y));
    }

    if(k == 1){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < coords.size(); i++){
        for(int j = i + 1; j < coords.size(); j++){
            g[i].push_back(make_pair(j, (abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second))));
            g[j].push_back(make_pair(i, (abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second))));
        }
    }
    long long result = -1, left = 1, right = 2 * 1e9, mid;
    
    while(left <= right){
        mid = (right + left) / 2;
        if(bfs(mid, k)){
            right = mid - 1;
            result = mid;
        }
        else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
}