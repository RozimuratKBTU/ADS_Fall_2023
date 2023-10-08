#include "bits/stdc++.h"

using namespace std;

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());


    int round;
    cin>>round;

    for (int i = 0; i < round; ++i) {
        int x;
        cin>>x;
        int cnt = 0;
        int sum =0 ;
        while(x >= v[cnt]){
            sum += v[cnt];
            cnt++;
            if(cnt == v.size()) break;
        }
        cout<<cnt<<" "<<sum<<endl;
    }


}
