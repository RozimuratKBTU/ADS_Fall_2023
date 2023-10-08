#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main(){
    char first[1000000];
    char second[1000000];
    int cnt1 = 0;
    int cnt2 = 0;
    string s = "#";
    cin>>first>>second;

    for (int i = 1; i < strlen(first); ++i) {
        if(first[i] ==s[0]){
            cnt1 += 1;
        }
    }
    for (int j = 1; j < strlen(second); ++j) {
        if (second[j] == s[0]){
            cnt2+=1;
        }
    }
    if ((strlen(first) - (2*cnt1)) == (strlen(second)-(2*cnt2))){
        cout<<"Yes";
    }
    else
        cout<<"No";


    return 0;
}