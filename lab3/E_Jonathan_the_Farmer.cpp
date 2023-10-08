#include <iostream>
#include "cmath"

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n][4];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin>>a[i][j];
        }
    }
    long long right = pow(10,9);
    long long left = 1;
    int ans = pow(10,9);
    while(left <= right){
        int temp = 0;
        int middle = left + (right - left)/2;

        for (int i = 0; i < n; ++i) {
            if(a[i][0] <= middle and a[i][1] <= middle and a[i][2] <= middle and a[i][3] <= middle) temp++;
        }
        if(temp < k){
            left = middle + 1;
        }
        else{
            ans = min(ans, middle);
            right = middle - 1;
        }

    }
    cout<<ans;

    return 0;
}