#include<bits/stdc++.h>

using namespace std;

class Heap{
    unsigned long long a[200005];
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

    void insert(unsigned long long val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    void sift_up(int i){
        while(i > 1 && a[parent(i)] > a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        if(l > size) return;
        int minChild = l;
        if(r <= size){
            if(a[r] < a[l]) minChild = r;
        }
        if(a[i] > a[minChild]){
            swap(a[i], a[minChild]);
            sift_down(minChild);
        }
    }

    unsigned long long extractMin(){
        unsigned long long ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }

    unsigned long long getMin(){
        return a[1];
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void change(int pos, int val){
        if(val > a[pos]){
            a[pos] = val;
        }
        else if(val < a[pos]){
            a[pos] = val;
            sift_down(pos);
        }
    }

};

int main(){
    Heap h;
    unsigned long long n, k;
    cin >> n >> k;
    unsigned long long sum = 0;
    for(int i = 0; i < n; i++){
        string s; unsigned long long num;
        cin >> s;
        if(s == "insert"){
            cin >> num;
            if(h.size < k){
                h.insert(num);
                sum += num;
            }
            else{
                if(h.getMin() < num){
                    sum -= h.getMin();
                    h.extractMin();
                    h.insert(num);
                    sum += num;
                }
            }
        }
        else cout << sum << endl;
    }
}