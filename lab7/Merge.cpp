#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &v1, vector<int> &v2){
    int i, j, k;
    i = j = k = 0;
    vector<int> tmp(v1.size() + v2.size());
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            tmp[k++] = v1[i++];
        }
        else{
            tmp[k++] = v2[j++];
        }
    }
    while(i < v1.size()) tmp[k++] = v1[i++];
    while(j < v2.size()) tmp[k++] = v2[j++];
    return tmp;
}

int main(){
    int n; cin >> n;
    vector<int> v1(n);
    for(int i = 0; i < n; i++) cin >> v1[i];
    int m; cin >> m;
    vector<int> v2(m);
    for(int i = 0; i < m; i++) cin >> v2[i];
    for(auto i : merge(v1, v2)) cout << i << " ";
}