#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_sort(int a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}

int main(){
    int n; cin >> n;
    int a[n];
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) cin >> a[i];
    quick_sort(a, 0, n - 1);
    int mindis = INT_MAX;
    for(int i = 0; i < n-1; i++){
        int dis = abs(a[i] - a[i + 1]);
        if(dis < mindis){
            mindis = dis;
            v.clear();
            v.push_back({a[i], a[i + 1]});
        }
        else if(dis == mindis){
            v.push_back({a[i], a[i + 1]});
        }
    }
    for(auto i : v) cout << i.first << " " << i.second << " ";
}