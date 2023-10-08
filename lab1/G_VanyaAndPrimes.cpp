//SuperPrimes
#include  <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[3911];
    bool t = true;
    bool v = true;
    int c = 1;
    int cnt = 0;
    for(int i = 2;i <= 3911; i++){
        for (int j = 2; j < i ; ++j) {
            if(i % j == 0){
                t = false;
                break;
            }
        }
        if(t){
            for (int j = 2; j < c; ++j) {
                if (c % j == 0) {
                    v = false;
                }
            }
            if (v){
                arr[cnt] = i;
//                cout<<i<<" ";
                cnt++;

            }
            v = true;
            c++;

        }
        t = true;
    }

    cout<<arr[n];

    return 0;
}