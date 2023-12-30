#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;
ll P = 31;
map <int,int> mp;
int total = 0;
ll get_hash(string &s){
    ll hash = 0;
    ll curP = 1;
    for(int i = 0; i < s.size();i++){
        ll curHash = (s[i] - 'a' + 1) * curP % MOD;
        hash = (hash + curHash) % MOD;
        curP = (curP * P) % MOD;
    }
    return hash;
}

vector <ll> get_prefix_hashes(string &s){
    vector <ll> hashes(s.size());
    ll curP = 1;
    for(int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * curP % MOD;
        if(i) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD; 
        }
        curP = (curP * P) % MOD;
    }
    return hashes;
}

void rabin_karp(string &s, string &t){
    if(t.size() > s.size()) return;
    ll small_hash = get_hash(t);
    vector <ll> hashes = get_prefix_hashes(s);
    for(int i = 0; i < s.size() - t.size() + 1; i++){
        ll hashDiff = hashes[i + t.size() - 1];
        if(i) hashDiff -= hashes[i - 1];
        if(hashDiff < 0) hashDiff += MOD;
        if(i) small_hash = (small_hash * P) % MOD;
        if(small_hash == hashDiff){
            if(mp.find(i) != mp.end())
            total +=1;
        mp[i] = 1;
        }
    }
}
int main(){
    string a,s,t; cin >> a >> s >> t;
    rabin_karp(a,t);
    rabin_karp(s,t);
    cout << total << endl;
}