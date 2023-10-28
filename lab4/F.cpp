#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this->val =val;
        right = left = nullptr;
    }
};

struct BST{
private:

    Node * root;

    Node * push(Node * cur,int val){
        if(cur == nullptr) return new Node(val);

        if(val < cur->val) cur->left = push(cur->left, val);

        if (val > cur->val) cur->right = push(cur->right, val);

        return cur;
    }

    void checkTriangle(Node * cur){
        if(cur != nullptr){
            checkTriangle(cur->left);
            if(cur->left != nullptr and cur->right != nullptr) cnt++;
            checkTriangle(cur->right);
        }
    }


public:
    BST() {
        root = NULL;
    }

    void push(int val){
        root = push(root, val);
    }

    void checkTriangle(){
        return checkTriangle(root);
    }

};

int main(){
    BST bst;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        bst.push(x);
    }
    bst.checkTriangle();
    cout<<cnt;
}