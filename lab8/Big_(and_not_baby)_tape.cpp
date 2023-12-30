#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;
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

void rabin_karp(string &s, string &t,vector <ll> &hashes, bool leg[] ){
    int cnt = 0;
    if(t.size() > s.size()) return;
    ll small_hash = get_hash(t);
    for(int i = 0; i < s.size() - t.size() + 1; i++){
        ll hashDiff = hashes[i + t.size() - 1];
        if(i) hashDiff -= hashes[i - 1];
        if(hashDiff < 0) hashDiff += MOD;
        if(i) small_hash = (small_hash * P) % MOD;
        if(small_hash == hashDiff){
            for(int k = i; k < i + t.size(); k++){
                leg[k] = true;
            }
        }
    }
}
int main(){
    string s;
    cin >> s;
    bool leg[s.size()];
    vector <ll> h = get_prefix_hashes(s);
    for(int i = 0; i < s.size(); i++){
        leg[i] = false;
    }
    int n;
    cin >> n;
    while(n--){
        string st;
        cin >> st;
        rabin_karp(s,st,h,leg);
        // for(int i = 0; i < s.size();i++){
        //     cout << leg[i] << " ";
        //  }
        //  cout << endl;
    }
    for(int i = 0; i < s.size(); i++){
        if(leg[i] == 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}