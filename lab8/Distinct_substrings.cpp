#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

long long MOD = 1e15 + 7;
long long P = 31;
long long getHash(string &s) {
    // long long hash = 0;
    // long long curP = 1;
    unordered_map<ll, bool> m;
    for (int i = 0; i < s.size(); i++) {
		  long long hash = 0;
	      long long curP = 1;
        for(int j = i ; j < s.size(); j++){
            ll curHash = ((s[j] - 96) * curP) % MOD;
            hash = (hash + curHash) % MOD;
            curP = (curP * P) % MOD;
            if(!m[hash]) {
                m[hash] = true;
            }
        }
    }
    return m.size();
}

int main(){
    unordered_map<ll, int> m;
    string s;
    cin>>s;
    cout<<getHash(s);
}