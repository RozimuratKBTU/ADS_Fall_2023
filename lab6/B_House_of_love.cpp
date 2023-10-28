#include "iostream"

using namespace std;

int partition(int a[], int low, int high){
    int i = low-1;
    int pivot = a[high];

    for (int j = low; j < high; ++j) {
        if(a[j] <= pivot){

            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);

    return i+1;
}

void quickSort(int a[], int low, int high){
    if(low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }

}

int main(){

    int n,m;
    cin>>n>>m;

    int a[n],b[m];

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>b[i];
    }

    quickSort(a, 0, n-1);
    quickSort(b, 0, m-1);

    int temp = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = temp; j < m; ++j) {
            if(a[i] == b[j]){
                cout<<b[j]<<" ";
                temp = j + 1;
                break;

            }
        }
    }

}