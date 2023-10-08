#include <iostream>
using namespace std;
bool find_prime(int n){\
     bool flag = true;
    if (n <= 1){
        return false;
    }

    for (int j = 2; j*j <= n; ++j) {
        if (n % j == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    if(find_prime(n))
        cout<<"YES";
    else
        cout<<"NO";


    return 0;
}