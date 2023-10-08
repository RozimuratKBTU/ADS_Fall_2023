#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    queue<int> S,K;
    for (int i = 0; i <s.size() ; ++i) {
        if(s[i] == 'S'){
            S.push(i);
        }
        else{
            K.push(i);
        }
    }

    while(!S.empty() and !K.empty()){
        if(S.front() < K.front()){
            S.push(S.front() + s.size());
        }
        else{
            K.push(K.front() + s.size());
        }
        K.pop();
        S.pop();
    }
    if (!S.empty()) {
        cout<<"SAKAYANAGI";
    }
    else cout<<"KATSURAGI";
    return 0;
}