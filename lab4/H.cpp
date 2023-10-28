#include "iostream"

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val) : val(val), right(nullptr), left(nullptr){};
};
int sum = 0;
struct BST{
    Node * root;
    BST(){
        root = nullptr;
    }
private:
    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node(val);

        if(val < cur->val) cur->left = push(cur->left, val);

        if(val > cur->val) cur->right = push(cur->right, val);

        return cur;
    }
    Node * treeSum(Node * cur){
        if(cur != nullptr) {
            treeSum(cur->right);
            sum += cur->val;
            cout <<sum<<" ";
            cur->val = sum ;
            treeSum(cur->left);
        }
        return nullptr;
    }
public:
    void push(int val){
        root = push(root,val);
    }
    void treeSum(){
        treeSum(root);
    }
};

int main(){
    int n;
    cin>>n;
    BST tree;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        tree.push(x);
    }
    tree.treeSum();

}