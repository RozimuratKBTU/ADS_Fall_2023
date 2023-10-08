#include <iostream>

using namespace std;

int VelocitySearch(int a[], int mid, int bags) {
    int totalHour = 0;
    for (int i = 0; i < bags; i++) {
        totalHour += (a[i] + mid - 1) / mid;
    }
    return totalHour;
}
int main () {
    int bags, hours;
    cin >> bags >> hours;
    int a[bags];
    int max = 0;
    for (int i = 0; i < bags; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < bags; i++) {
        if (a[i] > max) max = a[i];
    }

    int l = 1, r = max, mid, result;
    while(l <= r) {
        mid = l + (r - l)/ 2;
        if (VelocitySearch(a, mid, bags) <= hours) {
            result = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << result << endl;
}