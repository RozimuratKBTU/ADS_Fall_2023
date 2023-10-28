#include "iostream"


typedef unsigned long long ll;

using namespace std;

class Heap{
    ll a[200000];
public:
    int size;
    Heap(){
        a[0] = 0;
        size = 0;
    }

    int parent(int i){
        return i / 2;
    }
    int left(int i){
        return i  * 2;
    }
    int right(int i){
        return i * 2 + 1;
    }

    void insert(ll val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    void sift_up(int i){
        while(i > 1 and a[parent(i)] > a[i]){
            swap(a[parent(i)] , a[i]);
            i = parent(i);
        }
    }

    void sift_down(int i){
        int l = left(i);   //left == 2;
        int r = right(i);  // right = 3;    //parent == 1;
        if(l > size) return;
        int minChild = l;
        if(r <= size){
            if (a[r] < a[l]) minChild = r;
        }
        if(a[i] > a[minChild]){
            swap(a[i] , a[minChild]);
            sift_down(minChild);
        }
    }

    ll extractMin(){
        ll ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return  ans;
    }

    void print(){
        for (int i = 1; i <= size; ++i) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Heap h;
    int n; cin>>n;
    for (int i = 0; i < n; ++i) {
        ll x; cin >>x;
        h.insert(x);
    }

    ll  cost = 0;
    while(h.size > 1){
        ll mn = h.extractMin();
        ll smn = h.extractMin();
        h.insert(mn + smn);
        cost += mn + smn;
    }
    cout<<cost;
}