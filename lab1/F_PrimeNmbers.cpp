#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int count = 0, num = 1, i;

    while(count < n){
        num += 1;
        for ( i = 2; i <= num; ++i) {
            if ( num % i == 0){
                break;
            }
        }
        if(i == num){
            count++;
        }
    }
    cout<<num;

    return 0;
}