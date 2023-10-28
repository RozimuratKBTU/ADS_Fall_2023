#include "iostream"
#include "vector"

using namespace std;

int partition(vector<char> &v, int low, int high){
    int pivot = v[high];
    int i = low-1;
    for (int j = low; j < high; ++j) {
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return i+1;
}

void quickSort(vector<char>&v, int low, int high){
    if(low >= high){
        return;
    }else {
        int pivot = partition(v, low, high);
        quickSort(v, low, pivot - 1);
        quickSort(v, pivot + 1, high);
    }

}

int main(){

    int n;
    cin>>n;
    vector<char> v;
    for (int i = 0; i < n; ++i) {
        char x; cin>>x;
        v.push_back(x);
    }

    char x; cin>>x;

    quickSort(v, 0, v.size() - 1);


    if(v[v.size()-1] <= x){
        cout<<v[0];
    }else{
        for (int i = 0; i < v.size(); ++i) {
            if(v[i] > x){
                cout<<v[i];
                break;
            }
        }
    }
}