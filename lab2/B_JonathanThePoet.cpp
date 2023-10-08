#include "iostream"

using namespace std;

struct Node{
    string s;
    Node * next;
    Node * prev;
    Node(string s){
        this->s = s;
        next =NULL;
        prev = NULL;
    }
};
struct DL{
    Node * head;
    Node * tail;
    DL(){
        head = NULL;
        tail = NULL;
    }
    void add(string s){
        Node *node = new Node(s);
        if(head == NULL){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void print(){
        Node * node = head;
        while (node != NULL){
            cout<<node->s<<" ";
            node = node->next;
        }
    }
    void drop(){
        head = head->next;
    }
};

int main(){
    DL dl;
    int n,k;
    cin>>n>>k;

    while(n--) {
        string s;
        cin>>s;
        dl.add(s);
    }
    while(k--){
        dl.add(dl.head->s);
        dl.drop();
    }
    dl.print();
}