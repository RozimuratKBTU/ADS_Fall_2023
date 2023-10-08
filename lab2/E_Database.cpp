#include <iostream>

using namespace std;

struct Node{
    string s;
    Node * next;
    Node(string s, Node * next){
        this->next = next;
        this->s = s;
    }
};
struct ll{
    Node * head;
    Node * tail;
    ll(){
        head = NULL;
    }
    int cnt = 0;
    void add(string s){
        if(head ==NULL){
            Node * node = new Node( s, NULL);
//            head->next = node;
            head = node ;
            cnt++;
        }
        else if(head ->s != s){
            Node * node = new Node(s, head);
            head = node;
            cnt++;
        }
    }
    void print(){
        Node* cur  = head;
        cout<<"All in all: "<<cnt<<endl;
        cout<<"Students:"<<endl;
        while(cur != NULL){
            cout<<cur->s<<endl;
            cur = cur->next;
        }
    }
};

int main(){
    ll l;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        l.add(s);
    }
    l.print();
}