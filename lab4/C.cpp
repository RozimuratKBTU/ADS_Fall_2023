#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node() {

    }
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

struct BST {
    Node* root;
    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL) {
            node = new Node(val);
            return node;
        }
        else if (val <= node->data) {
            node->left = insert(node->left, val);
        }
        else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    Node* search(Node* node, int val) {
        if (node->data == val || node == NULL) {
            return node;
        }
        else if (val < node->data) {
            return search(node->left, val);
        }
        else {
            return search(node->right, val);
        }
    }

    void print_pre_order(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        print_pre_order(node->left);
        print_pre_order(node->right);
    }
};


int main() {

    int n;
    cin >> n;

    BST b;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        b.root = b.insert(b.root, x);
    }

    int f;
    cin >> f;
    Node* need = b.search(b.root, f);
    b.print_pre_order(need);
    return 0;
}