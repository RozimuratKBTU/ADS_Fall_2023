#include "iostream"
#include "vector"

using namespace std;

int partition(vector<char> &v, int low, int high){
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return i+1;
}

void quickSort(vector<char> &v, int low, int high){
    if(low < high){
        int pivot = partition(v, low, high);
        quickSort(v, low, pivot-1);
        quickSort(v,pivot+1, high);
    }
}

int main(){
    vector<char> v ;

    string s;
    cin>>s;

    for (int i = 0; i < s.size(); ++i) {
        v.push_back(s[i]);
    }

    quickSort(v, 0 , v.size() - 1);

    for (auto i : v) {
        cout<<i;
    }


    return 0;
}