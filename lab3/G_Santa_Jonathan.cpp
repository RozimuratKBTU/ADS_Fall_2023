#include <bits/stdc++.h>

using namespace std;


int index(vector<int> &v, int x, int left, int right){
    int middle = left + ((right - left) / 2);
    if (left > right) return  0;

    if (x >= v[middle]){
        if(middle == v.size()-1) return v.size();
        if(x < v[middle+1]) return middle+1;
        return index(v,x,middle+1, right);
    }else{
        if(middle == 0) return 0;
        if(x > v[middle -1]) return  middle;
        return index(v,x,left,middle-1);

    }
}

int main(){
    int n, f;
    cin>>n>>f;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int left = 0, right = v[n-1], right1 = v[n-1];
    int ans = 0;
    while(left <= right) {
        int middle = left + ((right - left)/2);
        if(middle == 0){
            cout<<1;
            return 0;
        }
        int maxFlights = (right1 % middle == 0) ? right1/middle : right1 / middle +1;
        int temp, num = 0, i = 1, flights = 0;
        while(i <= maxFlights){
            temp = num;
            num = index(v, middle*i, 0, v.size() - 1);
            flights += (num - temp) * i;
            i++;
        }
        if(flights > f) left = middle + 1;
        else{
            right = middle - 1;
            ans  = middle;
        }
    }
    cout << ans;
    return 0;
}
