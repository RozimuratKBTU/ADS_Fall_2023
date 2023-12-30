#include <bits/stdc++.h> 
using namespace std; 
 
vector<int> v1(110110, 0); 
vector<int> v2(110110, -1); 
 
void bfs(int x){ 
    queue<int> q; 
    q.push(x); 
    v1[x] = 1; 
 
    while(!q.empty()){ 
        int i = q.front(); 
        q.pop(); 
 
        if(i * 2 <= 1e4  && !v1[i * 2]){ 
            q.push(i * 2); 
            v1[i * 2] = v1[i] + 1; 
            v2[i * 2] = i; 
        } 
 
        if(i - 1 > 0 && !v1[i - 1]){ 
            q.push(i - 1); 
            v1[i - 1] = v1[i] + 1; 
            v2[i - 1] = i; 
        } 
    } 
} 
 
int main(){ 
    int n, k; cin >> n >> k; 
    bfs(n); 
    cout << v1[k] - 1 << '\n'; 
    vector<int> vect; 
 
    while(v2[k] != -1){ 
        vect.push_back(k); 
        k = v2[k]; 
    } 
    for(int i = vect.size() - 1; i >= 0; i--){
        cout << vect[i] << " ";
    }   
 
    return 0; 
}