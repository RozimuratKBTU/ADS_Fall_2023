#include <iostream>

using namespace std;

int binary(int a[], int n, int x, int left, int right){
    int mid = (left + right) / 2;

    if(x <= a[mid]){
        if(mid == 0) return 1;
        if(x > a[mid-1]) {
            return mid +1;
        }
        return binary(a,n,x,left,mid-1);
    }
    else if(x > a[mid]){
        if(x <= a[mid+ 1]) return mid + 2;
        return binary(a,n,x,mid+1, right);
    }

}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n], a2[k], num =0;

    for (int i = 0; i < n; ++i) {
        int x;cin>>x;
        a[i] = num + x;
        num+=x;
    }
    for (int i = 0; i < k; ++i) {
        cin>>a2[i];
    }
    for (int i = 0; i < k; ++i) {
        cout<<binary(a,n,a2[i],0,n-1)<<endl;
    }
}