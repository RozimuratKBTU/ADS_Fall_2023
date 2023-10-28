#include <iostream>

using namespace std;

struct Node{
    int val;
    Node * right;
    Node * left;
    Node(int val){
        this->val = val;
        right = nullptr;
        left = nullptr;
    }
};
struct BTS{
    Node * root;
    BTS(){
        root = nullptr;
    }
    Node * push(Node * current, int val){
        if(current == nullptr){
            return new Node(val);
        }
        if(val < current->val){
            current->left = push(current->left, val);
        }
        if(val> current->val) {
            current->right = push(current->right, val);
        }
        return current;
    }
    void push(int val){
        root = push(root, val);
    }
    Node * getRoot(){
        return root;
    }
};

int main(){
    BTS tree;
    string s;
    int n,m;
    cin>>n>>m;
    int x;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        tree.push(x);
    }
    for (int i = 0; i < m; ++i) {
        Node * current = tree.getRoot();
        bool exist = true;
        cin>>s;
        for (int j = 0; j < s.size(); ++j) {
            if(s[j] == 'L'){
                current = current->left;
            }
            if (s[j] == 'R'){
                current= current->right;
            }
            if(current == nullptr){
                exist = false;
                break;
            }
        }
        cout<<(exist ? "YES": "NO")<<endl;
    }

    return 0;
}