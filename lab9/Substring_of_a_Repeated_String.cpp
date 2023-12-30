#include <bits/stdc++.h>
using namespace std;
int k = 1;
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
bool KMP(string s, string patt) {
	string str = patt + '#' + s;
	vector <int> pi = prefix_function(str);
	for (int i = patt.size() + 1; i < str.size(); i++) {
		if (patt.size() == pi[i] ) {
            return true;
		}
	}
    return false;
}

int main() {
	string a, b;
	cin >> a >> b;
    string ss = a;
    int cnt = 0;
    while (a.size() < b.size()){
        a = a + ss;
        cnt++;
    }
    if (KMP(a, b)){
        cout << cnt + 1; 
        return 0;
    }
    if (KMP(a + ss, b)){
        cnt++;
        cout << cnt + 1;
        return 0;
    }
    cout << -1;
}