// #include <bits/stdc++.h>
// using namespace std;
// long long p = 1;

// int main(){
//     int n; cin >> n;
//     long long y = 0;
//     while(n--){
//         long long k; cin >> k;
//         cout << char( (k-y) / p +'a');
//         p *= 2;
//         y = k;
//     }
// }
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int p = 1;
char decryp(int n) {
	ull ans = (n / p) + 'a';
	p*=2;
	return char(ans);
}

int main() {
	int n;
	cin >> n;
	vector<ull> v;
	while (n--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                cout << decryp(v[i]);
                continue;
            }
            cout << decryp(v[i] - v[i - 1]);
	}
}