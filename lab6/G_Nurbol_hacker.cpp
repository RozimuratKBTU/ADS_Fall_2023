#include "bits/stdc++.h"

using namespace std;

bool compare(pair<string, string> &a, pair<string, string> &b){

    return a.first < b.first;
}

int partition(vector<pair<string, string>> &v, int left, int right){
    pair<string, string> pivot = v[right];
    int i = left;
    for (int j = left; j < right; ++j) {
        if(compare(v[i], pivot)){
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[right]);
    return i;
}

void quick_sort(vector < pair < string, string> >& v, int left, int right) {
    if (left < right) {
        int p = partition(v, left, right);
        quick_sort(v, left, p - 1);
        quick_sort(v, p + 1, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, string>> v;
    while (n--) {
        string oldNick, newNick;
        bool check = false;
        cin >> oldNick >> newNick;
        for (int i = 0; i < v.size(); ++i) {
            if (oldNick == v[i].second) {
                v[i].second = newNick;
                check = true;
                break;

            }
        }
        if (!check) {
            v.emplace_back(oldNick, newNick);
        }
    }

    quick_sort(v, 0, v.size() - 1);
    cout << v.size() << endl;

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << endl;
    }
}

