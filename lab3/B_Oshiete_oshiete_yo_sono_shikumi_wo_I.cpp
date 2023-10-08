#include <iostream>

using namespace std;

bool checkSum(int a[], int n, long long x, int k){
    long long cnt = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        if(a[i] > x) return false;
        else if(sum + a[i] > x){
            sum = a[i];
            cnt++;
        }else{
            sum += a[i];
        }
    }
    cnt++;
    return cnt <= k;
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    long long right = 0,left = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        right += a[i];
    }
    while(left <= right){
        long long middle = (left + right) / 2;
        if (checkSum(a,n,middle, k)){
            ans = middle;
            right = middle - 1;
        }else{
            left = middle + 1;
        }
    }
    cout<<ans;
}