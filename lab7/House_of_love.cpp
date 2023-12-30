#include<bits/stdc++.h>

using namespace std;

void merge(int a[], int l, int mid, int r){
    int i = l, j = mid + 1, k = l;
    int b[r + 1];
    while(i <= mid && j <= r){
        if(a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(int i = l; i <= r; i++) a[i] = b[i];
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

bool search(int a[], int l, int r, int x, vector<bool> &b){
    if(r == -1) return false;
    while(l + 1 < r){
        int mid = l + (r - l)/2;
        if(a[mid] >= x) r = mid;
        else l = mid;
    }

    while(!b[r] && a[r] == x && r < b.size()-1) r++;
    if(a[r] == x && b[r]){
        b[r] = false;
        return true;
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    vector<bool> b(m, true);
    for(int i = 0; i < n; i++) cin >> a1[i];
    for(int i = 0; i < m; i++) cin >> a2[i];
    mergeSort(a1, 0, n - 1);
    mergeSort(a2, 0, m - 1);

    for(int i = 0; i < n; i++){
        if(search(a2, -1, m-1, a1[i], b)) cout << a1[i] << " ";
    }
}