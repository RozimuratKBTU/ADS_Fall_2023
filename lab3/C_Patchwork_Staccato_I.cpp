#include "bits/stdc++.h"

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int cnt1 =0, cnt2 =0;
    for(int i = 0; i < m; i++){
        int x,y,z,w;
        cin>>x>>y>>z>>w;
        for (int j: v) {
            if(x<= j and j <= y){
                cnt1++;
            }
            else if(z <= j and j <= w){
                cnt2++;
            }
        }
        cout<<cnt1+cnt2<<endl;
        cnt2 = 0;
        cnt1 = 0;
    }




}