#include <bits/stdc++.h>
using namespace std;

long long pairCount(map<string, int> &d) {
    long long sum = 0;
    for (auto i : d)
        sum += (static_cast<long long>(i.second) * (i.second - 1)) / 2;

    return sum;
}


long long difference(vector<string> &array, int m) {

    map<string, int> changed, same;

    for (auto s : array) {

        same[s]++;

        for (int i = 0; i < m; i++) {
            string t = s.substr(0, i) + "//" + s.substr(i + 1);


            changed[t]++;
        }
    }

    return pairCount(changed) - pairCount(same) * m;
}

int main() {
    int t = 0,n = 0, m = 2;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<string> arr(n);
        for (int j = 0; j < n; j++)
        {
            string a;cin >> a;
            arr[j] = a;
        }
        cout << difference(arr, m) << endl;
    }
    return 0;
}