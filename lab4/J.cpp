#include "bits/stdc++.h"
#include "cmath"

using namespace std;

struct  Node{
    int val;
    Node * right;
    Node * left;
    Node(int val){
        this->val = val;
        right = left = NULL;
    }
};

Node * arrayBST(Node * node, int a[],int l, int r ){
    if(l > r) return nullptr;

    int mid = (l+r)/ 2;
    int val = a[mid];
    node = new Node(val);

    node->left = arrayBST(node->left, a,l,mid-1);
    node->right = arrayBST(node->right, a,mid+1, r);

    return node;
}

void bst(Node * node){
    queue< Node * > q;
    q.push(node);
    while (!q.empty()){
        Node * cur = q.front();
        cout<<cur->val<<" ";
        q.pop();

        if(cur->left != NULL){
            q.push(cur->left);
        }
        if(cur->right != NULL){
            q.push(cur->right);
        }
    }
}

int main(){
    int n;
    cin >>n;

    n = pow(2,n) - 1;
    int a[n];
    Node * root = NULL;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a, a+n);
    root = arrayBST(root, a, 0, n-1);
    bst(root);

}