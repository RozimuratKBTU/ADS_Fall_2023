#include <iostream>

using namespace std;

bool binary_func(int a[],int k,int left, int right ){
    int mid = (left + right) / 2;
    if(left > right) return false;
    if(a[mid] == k) return true;
    else if (k < a[mid]) return binary_func(a, k, left, mid-1);
    else return binary_func(a,k,mid+1, right);
}

int main(){
    int n;cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int k; cin>>k;

    if(binary_func(a,k,0,n-1)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return  0;
}