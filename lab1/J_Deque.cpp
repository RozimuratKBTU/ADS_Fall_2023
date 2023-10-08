#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dec;
    char ch;

    while(cin>>ch){
        if (ch =='+'){
            int n;
            cin>>n;
            dec.push_front(n);
        }
        else if (ch =='-'){
            int n; cin>>n;
            dec.push_back(n);
        }
        else if (ch == '*'){
            if(!dec.empty()){
                cout<<dec.front() + dec.back()<<endl;
                dec.pop_front();
                if (!dec.empty()){
                    dec.pop_back();
                }
            }
            else{
                cout<<"error"<<endl;
            }
        }
        if(ch == '!'){
            break;
        }
    }

    return 0;
}