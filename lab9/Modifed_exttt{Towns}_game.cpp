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

int main() {

	string s, t;
	int n;
	vector<string> city;
	cin >> s >> n;
	vector<pair<string, int>> v;
	int maxx = 1;
	while (n--) {
		cin >> t;
		t[0] = tolower(t[0]);
		vector<int> pi = prefix_function(t+'#'+s);
		maxx = max(maxx, pi[pi.size() - 1]);
		v.push_back(make_pair(t, pi[pi.size()-1]));
	}

	for (auto i : v) {
			if(i.second > maxx){
				maxx = i.second;
				city.clear();
				city.push_back(i.first);
			}
			else  if (i.second == maxx) {
				city.push_back(i.first);
			}
	}
	cout << city.size() << endl;
	for (auto i : city) {
		i[0] = toupper(i[0]);
		cout << i << endl;
	}
}