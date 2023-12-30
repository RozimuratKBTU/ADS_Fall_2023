#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}
// ll strr(string &s,ll k){
//     string ans ="";
//     int k = ( k - 1) + 1;
//     vector <int> pi = prefix_function(s);
//     string suff = s.substr(0, s.size() - pi[pi.size() - 1]) ;
//     for(int i = 1; i < k ; i++){
//         ans +=(k - 1) * suff;
//         }
//     ans+=s;
//     return ans.length();
// }
// int main(){
//     ll n,k;
//     string s;
//     cin >> n;
//     for(int i = 0; i < n ; i++){
//         cin >> s >> k;
//         cout << strr(s, k) << endl;
// }
int main() {
    int t; cin >> t;
    string s; int k;
    while (t--){
        cin >> s >> k;
        vector <int> pi = prefix_function(s);
        int end = pi.size() - 1;
        int task_name_length = (s.size() - pi[end]) * k + pi[end];
        cout << task_name_length << endl;
    }
}

