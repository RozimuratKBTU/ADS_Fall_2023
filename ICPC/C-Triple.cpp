#include <iostream>
#include "algorithm"
#include "vector"
#include "bits/stdc++.h"

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if((arr[i] == arr[i+1] )and (arr[i] == arr[i+2])){
                cnt=1;
                cout<<arr[i]<<endl;
                break;
            }
        }
        if(cnt == 0){
            cout<<-1<<endl;
        }
    }


    return 0;
}