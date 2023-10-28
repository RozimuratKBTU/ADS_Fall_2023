#include <iostream>

using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if( a[j] > pivot){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}

void quickSort(int a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a,pi+1, high);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int b[m][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[j][i];
        }
    }

    for (int i = 0; i < m; ++i) {
        quickSort(b[i], 0, n-1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <m; ++j) {
            cout<<b[j][i]<<" ";
        }
        cout<<endl;
    }
}


