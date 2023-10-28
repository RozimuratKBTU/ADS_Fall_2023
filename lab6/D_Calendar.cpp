#include <iostream>
#include "vector"
using namespace std;

struct Date{
    int month, day, year;
};

int compare(Date a, Date b){
    if(a.year == b.year){
        if(a.month == b.month){
            if(a.day == b.day) return true;
            return a.day < b.day;
        }
        return a.month < b.month;
    }
    return a.year < b.year;
}

int partition(vector<Date> &v, int low, int high){
    int i = low - 1;
    Date pivot = v[high];

    for (int j = low; j < high; ++j) {
        if(compare(v[j] , pivot)){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);

    return i+1;
}



void quickSort(vector<Date>&v, int low, int high){
    if(low < high) {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

int main(){

    int n;cin>>n;
    vector<Date> v(n);
    for (auto &dates: v) {
        int y,d,m;
        char z;
        cin>>d>>z>>m>>z>>y;
        dates.year = y;
        dates.month = m;
        dates.day = d;
    }
    quickSort(v, 0, v.size() -1);

    for (auto i: v) {
        (i.day < 10) ? cout<<0<<i.day<<"-" : cout<<i.day<<"-";
        (i.month < 10) ?  cout<<0<<i.month<<"-" : cout<<i.month<<"-";
        cout<<i.year;
        cout<<endl;
    }

}