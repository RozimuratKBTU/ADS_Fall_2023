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
    vector <int> p;
    int cnt = 0;
    for(int i = 0; i < str.size(); i++){
        if(pi[i] == t.size()) {
            p.push_back((i - 2 * t.size()) + 1);
        }
    }
    cout << p.size() << endl;
    for(auto i : p){
        cout << i << " ";
    }
}