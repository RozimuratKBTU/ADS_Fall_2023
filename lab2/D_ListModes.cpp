#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

int main(){
    vector <int> v;
    int n;
    cin>>n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i <= n-1; ++i) {
        for (int j = i+1; j <n ; ++j) {
            if(a[i] < a[j]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    int maxCnt = 0;

    int size = sizeof(a)/sizeof (int);

    for (int i = 0; i < size; ++i) {
        int cnt = 0;
        for (int j = 0; j < size; ++j) {
            if (a[j] == a[i]) {
                cnt++;
            }
        }
        if (cnt > maxCnt) {
            maxCnt = cnt;
            v.clear();
            v.push_back(a[i]);
        } else if (cnt == maxCnt) {
            v.push_back(a[i]);
        }
    }


    for (int i = 0; i < v.size()-1; ++i) {
        for (int j = i+1; j < v.size(); ++j) {
            if(v[i] == v[j]){
                v.erase(unique(v.begin(), v.end()), v.end());
            }
        }
    }

    for(auto i : v){
        cout<<i<<" ";
    }
}
