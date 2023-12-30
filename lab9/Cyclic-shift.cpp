#include <bits/stdc++.h>
using namespace std;

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
int main(){
    string s,t;
    cin >> s >> t;
    string str = t + '#' + s;
    vector <int> pi = prefix_function(str);
    rotate(s.begin(),s.begin()+(s.size() - pi[pi.size() - 1]),s.end());
    if(s == t) cout << pi[pi.size() - 1];
    else cout << -1;
}