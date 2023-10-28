#include <iostream>
#include "cmath"

using namespace std;

struct Node{
    int val;
    Node * left;
    Node *  right;
    Node(int val){
        this->val = val;
        right = left = NULL;
    }
};
struct BST{
private:
    int sum = 0;
    Node * root;

    Node * push(Node * node, int val){
        if(node == NULL) return new Node(val);
        if(val < node->val) node->left = push(node->left, val);
        if(val > node->val) node->right = push(node->right, val);
        return node;
    }

    void print(Node * cur, int lvl){
        if(cur != nullptr){
            if(lvl == 0){
                sum += cur->val;
            }else{
                print(cur->left, lvl-1);
                print(cur->right, lvl-1);
            }
        }else{
            return;
        }
    }

    int height(Node * cur){
        if(cur == NULL) return 0;
        return max(height(cur->left), height(cur->right)) + 1;
    }



public:
    BST(){
        root = NULL;
    }

    void push(int val){
        root = push(root, val);
    }

    void print(){
        int h = height();
        cout<<h<<endl;
        for (int i = 0; i < h; ++i) {
            print(root, i);
            cout<<sum<<" ";
            sum = 0;
        }
    }

    int height(){
        return height(root);
    }
};

int main(){
    BST tree;
    int n,x;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        tree.push(t);
    }
    tree.print();
}