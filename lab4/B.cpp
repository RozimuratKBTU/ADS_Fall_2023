#include "iostream"

using namespace std;

struct Node{
    int val;
    Node * right;
    Node * left;
    Node(int val){
        this->val = val;
        right = left = NULL;
    }
};

struct  BST{
    Node * root;
    BST(){
        root =NULL;
    }
private:
    Node * push(Node * cur, int val){
        if(cur == NULL) return new Node(val);

        if(val < cur->val) cur->left = push(cur->left, val);

        if(val > cur->val) cur->right = push(cur->right, val);

        return cur;
    }

public:
    void insert(int val){
        root = push(root, val);
    }

    Node *  find(int target){
        Node * node = root;
        while(node->val != target){
            if(target < node->val){
                node = node->left;
            }else{
                node = node->right;
            }
        }
        return node;
    }
    int getSubTree(Node * node){
        if(node == nullptr) return 0;
        else return (getSubTree(node->left) + getSubTree(node->right) + 1);
    }

};

int main(){
    BST tree;
    int n,k;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        tree.insert(x);
    }
    cin>>k;
    Node * find_k  = tree.find( k);
    cout<< tree.getSubTree(find_k);

    return 0;
}