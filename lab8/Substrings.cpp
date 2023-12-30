#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 9;
ll P = 31;
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
    ll curP = 1;
    vector <ll> hashes(s.size());
    for(int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * curP % MOD;
        if(i) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD; 
        }
        curP = (curP * P) % MOD;
    }
    return hashes;
}

int rabin_karp(string &s, string &t,vector <ll> &hashes ){
    int cnt = 0;
    ll small_hash = get_hash(t);
    for(int i = 0; i < s.size() - t.size() + 1; i++){
        ll hashDiff = hashes[i + t.size() - 1];
        if(i) hashDiff -= hashes[i - 1];
        if(hashDiff < 0) hashDiff += MOD;
        if(i) small_hash = (small_hash * P) % MOD;
        if(small_hash == hashDiff){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    string s;
    cin >> s;
    vector <ll> hashes = get_prefix_hashes(s);
    int n;
    cin >> n;
    while(n--){
        int left, right;
        cin >> left >> right;
        left -- ;
        string st = "";
        for(int i = left; i < right; i++){
            st += s[i];
        }
        cout << rabin_karp(s, st, hashes) << endl;
    }
}