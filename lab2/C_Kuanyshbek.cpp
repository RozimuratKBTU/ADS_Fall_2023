#include <iostream>

using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
struct ll{
    Node *head, *tail;
    ll(){
        head= tail = NULL;
    }
    void add(int x){
        Node * node = new  Node(x);
        if(head == NULL){
            head = tail = node;
        }
        else{
            tail->next=node;
            tail = node;
        }
    }
    void print(){
        Node * current = head;
        while(current != NULL){
            cout<<current->val<<" ";
            current = current->next;
        }
    }
};

int main(){
    ll l;
    int n;cin>>n;
    for (int i = 0; i < n; ++i) {
        int k;cin>>k;
        if(i % 2 == 0){
            l.add(k);
        }
    }
    l.print();
}