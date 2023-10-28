#include<bits/stdc++.h>

using namespace std;

class Heap{
    int a[100005];
public:
    int size;
    Heap(){
        a[0] = INT_MAX;
        size = 0;
    }

    int parent(int i){
        return i / 2;
    }

    int left(int i){
        return i * 2;
    }

    int right(int i){
        return i * 2 + 1;
    }

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    void sift_up(int i){
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        if(l > size) return;
        int maxChild = l;
        if(r <= size){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild);
        }
    }

    int extractMax(){
        int ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Heap h;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        h.insert(x);
    }

    while(h.size > 1){
        int x = h.extractMax();
        int y = h.extractMax();
        if(x > y) h.insert(x - y);
    }
    if(h.size == 0) cout << 0;
    else h.print();
}