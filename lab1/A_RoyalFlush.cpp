#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt = 0;
    while(n--){
        int x;
        cin>>x;
        deque<int> dec;
        for(int i = x; i > 0; i--){
            dec.push_front(i);
            cnt = i;
            while(cnt--){
                dec.push_front(dec.back());
                dec.pop_back();
            }
        }
        for(int j : dec){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}