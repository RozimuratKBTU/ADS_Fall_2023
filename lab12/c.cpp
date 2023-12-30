#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 

vector<int>g_roadways[410]; 
vector<int>g_airlanes[410]; 
int ar[405][405]; 

int main(){ 
    int k,m; 
    cin >> k >> m; 
    for(int i=0;i<m;i++){ 
        int a,b; 
        cin >> a >> b; 
        a--; 
        b--; 
        g_roadways[a].push_back(b); 
        g_roadways[b].push_back(a); 
        ar[a][b] = 1; 
        ar[b][a] = 1; 
    } 
    for (int i = 0; i < k; i ++){ 
        for (int j = 0; j < k; j ++){ 
            if (ar[i][j] == 0 && i != j){ 
                g_airlanes[i].push_back(j); 
            } 
        } 
    } 
    queue<int>q1; 
    vector<int>d1(k+1); 
    vector<bool>used1(k+1); 
    q1.push(0); 
    used1[0] = true; 
    while(!q1.empty()){ 
        int v = q1.front(); 
        q1.pop(); 
        for(int i=0;i<g_roadways[v].size();i++){ 
            int to = g_roadways[v][i]; 
            if(!used1[to]){ 
                used1[to] = true; 
                q1.push(to); 
                d1[to] = d1[v]+1; 
            } 
        } 
    } 
    queue<int>q2; 
    vector<int>d2(k+1); 
    vector<bool>used2(k+1); 
    q2.push(0); 
    used2[0] = true; 
    while(!q2.empty()){ 
        int v = q2.front(); 
        q2.pop(); 
        for(int i=0;i<g_airlanes[v].size();i++){ 
            int to = g_airlanes[v][i]; 
            if(!used2[to]){ 
                used2[to] = true; 
                q2.push(to); 
                d2[to] = d2[v]+1; 
            } 
        } 
    } 
    if (!used1[k-1] || !used2[k-1]){ 
        cout << -1; 
    } 
    else { 
        cout << max(d1[k-1], d2[k-1]); 
    } 
}