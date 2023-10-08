#include "iostream"

using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int data){
        next =NULL;
        this->data = data;
    }
};
class LinkedList{
public:
    Node * head;
    Node * tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void add(int data){
        Node * temp = new Node(data);
        if(head == NULL){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }
    void print(int data, int position){
        Node * cur = head;
        int cnt = 0;
        while(cur != NULL){
            if(cnt == position){
                cout<<data<<" ";
                cnt++;
                continue;
            }
            cout<<cur->data<<" ";
            cur = cur->next;
            cnt++;
        }
    }
};

int main(){
    LinkedList ll;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        ll.add(x);
    }
    int k,pos;
    cin>>k>>pos;
    ll.print(k,pos);

}