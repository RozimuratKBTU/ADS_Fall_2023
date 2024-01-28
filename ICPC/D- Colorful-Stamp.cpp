#include "iostream"

using namespace std;


int main(){
    int number;
    cin>>number;
    while (number--) {
        int n;
        cin >> n;
        string s;
        int ans = 0;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'W') {
                int b = 0, r = 0;
                while (i < n and s[i] != 'W') {
                    if (s[i] == 'R') r++;
                    else b++;
                    i++;
                }
                if (b == 0 || r == 0) {
                    ans = 1;
                    break;
                }
            }
        }
        cout << (ans == 0 ? "YES" : "NO") << endl;
    }
}