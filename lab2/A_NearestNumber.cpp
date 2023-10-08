#include <iostream>
#include <vector>

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
    int k;cin>>k;
    int near = v[0];
    int min_dif = abs(v[0] - k);

    for(int i = 0; i < v.size(); ++i) {
        int dif = abs(v[i] - k);

        if(dif < min_dif){
            near = v[i];
            min_dif = dif;
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        if(v[i] == near){
            cout<<i;
            break;
        }
    }

}