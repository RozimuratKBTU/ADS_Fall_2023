#include "iostream"

using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while (t--){
        ll n,m,i,j;
        cin>>n>>m;
        string a[n];
        for ( i = 0; i <n; ++i) {cin>>a[i];}

        for (int k = n; k >0; --k) {
            for ( i = n-2; i >=0 ; i--) {
                for (j = 0; j <m ; ++j) {
                    if(a[i][j] == '*' and a[i+1][j] =='.'){
                        a[i][j] = '.';
                        a[i+1][j] = '*';
                    }
                }
            }
        }
        cout<<"\n";
        for (i = 0;  i<n ; i++) {
            cout<<a[i]<<endl;
        }
    }

    return 0;
}