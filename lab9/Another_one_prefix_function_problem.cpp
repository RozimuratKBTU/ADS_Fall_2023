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
    string s;
    cin >> s;
    // string str = t + '#' + s;
    vector <int> pi = prefix_function(s);
    int cnt = 0;
    vector <int> p;
    for(int i = 0; i < s.size(); i++){
        if(pi[i] == 0) {
            p.push_back((i + 1));
        }
    }
    cout << s.size() - pi[pi.size() - 1] ;
    // for(auto i : pi){
    //     cout << i << " "
    // }
}
