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

void rabin_karp(string &s, pair <string, int> &k, int &maxx){
    if(k.first.size() > s.size()) return;
    ll small_hash = get_hash(k.first);
    vector <ll> hashes = get_prefix_hashes(s);
    for(int i = 0; i < s.size() - k.first.size() + 1; i++){
        ll hashDiff = hashes[i + k.first.size() - 1];
        if(i) hashDiff -= hashes[i - 1];
        if(hashDiff < 0) hashDiff += MOD;
        if(i) small_hash = (small_hash * P) % MOD;
        if(small_hash == hashDiff){
            k.second++;
            maxx = max(maxx,k.second);
        }
    }
}

int main(){
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        pair <string, int> st[n];
        for(int i = 0; i < n; i++){
            cin >> st[i].first;
            st[i].second = 0;
        }
    string s;
    cin >> s;
    int maxx = INT_MIN;
    for(int i = 0; i < n; i++){
        rabin_karp(s, st[i], maxx);
    }
    cout << maxx << endl;
    for(int i = 0; i < n; i++){
        if(st[i].second == maxx){
            cout << st[i].first << endl;
        }
    }
}
}