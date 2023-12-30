#include <bits/stdc++.h> 
using namespace std; 
int n, m; 
vector<int> v[110110]; 
int b[110110]; 
int c[110110]; 
 
void BFS(int x) 
{ 
    queue<int> q; 
    q.push(x); 
    b[x] = x; 
     
    while(!q.empty()){ 
        int a = q.front(); 
        q.pop(); 
        for(int i : v[a]){ 
            if (!b[i]){ 
                b[i] = a; 
                c[a]++; 
                q.push(i); 
            } 
        } 
    } 
} 
 
int main() 
{ 
    cin >> n >> m; 
    for(int i = 0; i < m; i++) 
    { 
        int a, b; 
        cin >> a >> b; 
        v[a].push_back(b); 
        v[b].push_back(a); 
    } 
 
    int count = 0; 
    for(int i = 1; i <= n; i++) 
    { 
        if (!b[i]) { 
            BFS(i); 
        } 
    } 
 
    for(int i = 1; i <= n; i++) 
    { 
        if (b[i] != i){ 
            if (c[i] > c[b[i]]){ 
                count++; 
            } 
        } 
        else count++; 
    } 
    cout << count; 
    return 0;
}