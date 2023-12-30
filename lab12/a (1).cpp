#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    int a[k][k];
    unordered_map<int, bool> m;
    for(int i = 0; i < k; i++) {
        m[i] = true;
        for(int j = 0; j < k; j++) cin >> a[i][j];
    }   

    for(int t = 0; t < k; t++){
        int x;
        cin >> x;
        x--;
        m[x] = false;
        int result = 0;
        for(int i = 0; i < k; i++){
                for(int j = 0; j < k; j++){
                        a[i][j] = min(a[i][j], a[i][x] + a[x][j]);
                }
        }
        for(int i = 0; i < k; i++){
            if(!m[i]){
                for(int j = 0; j < k; j++){
                    if(!m[j]){
                        result = max(result, a[i][j]);
                    }
                }
            }
        }
        cout << result << endl;
    }
    
    return 0;
}