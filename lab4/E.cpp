#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right ;
    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

struct BST{
private:
    Node*root;
    int cnt = 0;

    Node * push(Node * cur, int val,int z){
        if(cur == nullptr) return new Node(val);
        if(z == 0) cur->left = push(cur->left, val, z);
        else if(z == 1) cur->right = push(cur->right, val, z);
        return cur;
    }
    Node * push2(Node * cur,int val,int son,int z){
        if(cur != nullptr){
            if(cur->val == val) push(cur, son, z);
            push2(cur->left, val, son, z);
            push2(cur->right, val, son, z);
        }
        return nullptr;
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return max(height(cur->left) , height(cur->right)) + 1;
    }



public:
    void push(int x,int y, int z){
        push2(root, x,y,z);
    }

    void levels(Node * cur, int level){
        if(!cur) return ;
        if(level == 0){
            cnt++;
        }else{
            levels(cur->left, level - 1);
            levels(cur->right, level - 1);

        }

    }

    int levels(){
        int h = height(root);
        int mx = INT16_MIN;
        for (int i = 0; i < h; ++i) {
            levels(root, i);
            if(cnt > mx){
                mx = cnt;
            }
            cnt = 0;
        }
        return mx;
    }

    void pushMainRoot(){
        root = new Node(1);
    }
};

int main(){
    BST bst;
    int  n;
    cin>>n;

    bst.pushMainRoot();

    int x,y,z;
    for (int i = 0; i < n-1; ++i) {
        cin>>x>>y>>z;
        bst.push(x,y,z);
    }

    cout<<bst.levels();

}