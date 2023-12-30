#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    int sum1 = 0, sum2 = 0;
    for(auto &i : a) sum1 += i;
    for(auto &i : b) sum2 += i;
    if(sum1 == sum2){
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) return a[i] < b[i];
        }
        return true;
    }
    return sum1 > sum2;
}

void merge(vector<vector<int>> &v, int l, int mid, int r){
    int i = l, j = mid + 1, k = l;
    vector<vector<int>> tmp(r + 1);
    while(i <= mid && j <= r){
        if(cmp(v[i], v[j])) tmp[k++] = v[i++];
        else tmp[k++] = v[j++];
    }
    while(i <= mid) tmp[k++] = v[i++];
    while(j <= r) tmp[k++] = v[j++];
    for(int i = l; i <= r; i++) v[i] = tmp[i];
}

void mergeSort(vector<vector<int>> &v, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        vector<int> row(m);
        for(auto &j : row) cin >> j;
        v.push_back(row);
    }
    mergeSort(v, 0, v.size()-1);
    for(auto row : v){
        for(auto i : row) cout << i << " ";
        cout << endl;
    }
}