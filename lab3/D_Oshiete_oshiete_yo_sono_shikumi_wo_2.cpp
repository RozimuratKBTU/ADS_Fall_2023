#include <bits/stdc++.h>
using namespace std;

int right(int a[], int y, int l, int r){
    int m = l + (r-l)/2;
    if(l == m) return m;
    if(a[m] <= y) return right(a, y, m, r);
    else return right(a, y, l, m);
}

int left(int a[], int x, int l, int r){
    int m = l + (r-l)/2;
    if(l == m) return m+1;
    if(a[m] >= x) return left(a, x, l, m);
    else return left(a, x, m, r);
}
int binary(int a[], int l, int r, int x, int y){
    int lev = left(a, x, l, r);
    int prav = right(a, y, l, r);
    int ans = (prav-lev)+1;
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    for(int i = 0; i < m; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 <=l2 && r2 <= r1){
            cout << binary(a, -1, n, l1, r1) << endl;
        }
        else if(l2 <= l1 && r1 <= r2){
            cout << binary(a, -1, n, l2, r2) << endl;
        }
        else if(l1 <= l2 && l2 <= r1){
            cout << binary(a, -1, n, l1, r2) << endl;
        }
        else if(l2 <= l1 && l1 <= r2){
            cout << binary(a, -1, n, l2, r1) << endl;
        }
        else{
            cout << binary(a, -1, n, l1, r1) + binary(a, -1, n, l2, r2) << endl;
        }
    }
    return 0;
}