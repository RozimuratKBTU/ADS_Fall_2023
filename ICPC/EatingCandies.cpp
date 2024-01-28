#include "iostream"

typedef long long ll;

using namespace std;


int main(){
    ll t;cin>>t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n], i;
        for (i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll f = 0, l = n-1;
        ll ans = 0, ls = 0, fs = 0;

        while(f <= l){
            if(fs >= ls){
                ls += a[l];
                l--;
            } else{
                fs += a[f];
                f++;
            }
            if(fs == ls){
                ans = f+n-l-1;
//                cout<<f<<" "<<n<<" "<<l<<endl;
            }
        }

        cout<<ans;
        cout<<endl;
    }


    return 0;
}