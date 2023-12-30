#include<bits/stdc++.h>

using namespace std;

bool comp(string a, string b, int i, int j){
    if(a.size() == b.size()){
        return i < j;
    }
    return a.size() < b.size();
}
void merge(vector<string> &v, int l, int mid, int r){
    int i, j, k;
    i = l;
    j = mid + 1;
    k = l;
    vector<string> tmp(r + 1);
    while(i <= mid && j <= r){
        if(comp(v[i], v[j], i, j)){
            tmp[k++] = v[i++];
        }
        else{
            tmp[k++] = v[j++];
        }
    }
    for(; i <= mid; i++){
        tmp[k] = v[i];
        k++;
    }

    for(; j <= r; j++){
        tmp[k] = v[j];
        k++;
    }
    for(int i = l; i <= r; i++){
        v[i] = tmp[i];
    }
}

void mergeSort(vector<string> &v, int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}

int main(){
    int n; cin >> n;
    vector< vector<string>> v;
    for(int j = 0; j < n+1; j++){
        string s;
        getline(cin, s);
        string tmp = "";
        vector<string> row;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' ') tmp += s[i];
            if(s[i] == ' ' || i == s.size()-1){
                row.push_back(tmp);
                tmp = "";
            }
        }
        if(j == 0) continue;
        v.push_back(row);
    }

    for(int i = 0; i < v.size(); i++){
        mergeSort(v[i], 0, v[i].size()-1);
    }

    for(auto row : v){
        for(auto i : row) cout << i << " ";
        cout << endl;
    }

}