#include <bits/stdc++.h>
using namespace std;

string calc_hash(string s, long long q = 1e9 + 7) {
	long long p = 1;  
	long long hashed = 0;
	for (long long i = 0; i < s.length(); i++) { 
		hashed = (hashed + (s[i] - 47) * p) % q; 
       
		p = (p * 11) % q; 
	}
	return to_string(hashed);
}


int main(){
    vector <string> v;
	int cnt = 0;
    long long n; cin >> n;
	map<string, bool> mp;
    for(long long i = 0; i < 2 * n; i++){ 
        string s;
        cin >> s;
        v.push_back(s);
		mp[s] = true;
    }
    for(auto &i : v){
		string s = calc_hash(i);
			if(cnt == n) return 0;
            if(mp[s] == true){
                cout << "Hash of string " << '"' << i << '"' << " is " << s << endl;
				cnt++;
            }
        }}
    