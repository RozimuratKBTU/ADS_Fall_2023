#include <iostream>

using namespace std;

struct Node{
    int val;
    Node*right;
    Node*left;
    Node(int val){
        this->val = val;
        right =left = nullptr;
    }
};
int maxDistance =0;

struct BTS{
private:
    Node*root;

    Node * push(Node * cur, int val){
        if(cur == nullptr) return new Node(val);

        if(val < cur->val) cur->left = push(cur->left, val);

        if(val > cur->val) cur->right = push(cur->right, val);

        return cur;
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return max(height(cur->right), height(cur->left)) + 1;
    }

    void find(Node * cur){
        if(cur != nullptr){
            if(height(cur->right) + height(cur->left) + 1 > maxDistance)
                maxDistance = height(cur->right) + height(cur->left) + 1;
            find(cur->left);
            find(cur->right);
        }
    }

public:
    BTS(){
        root = NULL;
    }
    int height(){
        return height(root);
    }
    void push(int val){
        root = push(root, val);
    }
    void find(){
        find(root);
    }
};

int main(){
    int n;
    cin>>n;
    BTS tree;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        tree.push(x);
    }
    tree.find();
    cout<<maxDistance;
}