#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

struct bst{
public:
    bst(){
        root = NULL;
    }
    void add(int val){
        root = add(root, val);
    }
    void print(){
        print(root);
    }
    bool find(int val){
        return find(root, val) != NULL;
    }
    void del(int val){
        root = del(root, val);
    }

private:
    node * root;

    node * add(node * current, int val){
        if(current == NULL){
            current = new node(val);
        }
        else if(val < current->val){
            current->left = add(current->left, val);
        }
        else if(val > current->val){
            current->right = add(current->right, val);
        }
        return current;
    }

    void print(node * current){
        if(current != NULL){
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }

    node * find(node * current, int val){
        if(current == NULL) return NULL;
        if(current->val == val) return current;
        if(current->val < val) return find(current->right, val);
        return find(current->left, val);
    }

    node * rightmost(node * current){
        if(current == NULL) return NULL;
        if(current->right == NULL) return current;
        return rightmost(current->right);
    }

    node * del(node * current, int val){
        if(current == NULL) return NULL;
        if(current->val == val){
            if(current->left == NULL && current->right == NULL){
                delete current;
                return NULL;
            }else if(current->left == NULL && current->right != NULL){
                node * temp = current->right;
                delete current;
                return temp;
            }else if(current->left != NULL && current->right == NULL){
                node * temp = current->left;
                delete current;
                return temp;
            }else if(current->left != NULL && current->right != NULL){
                node * temp = rightmost(current->left);
                if(temp != NULL){
                    current->val = temp->val;
                }
                current->left = del(current->left, current->val);
            }
        }else if(current->val > val){
            current->left = del(current->left, val);
        }
        else if(current->val < val){
            current->right = del(current->right, val);
        }
        return current;
    }

};

int main(){

    int a[] = {10, 6, 7, 1, 2, 3, 5};
    int n = sizeof(a)/sizeof(int);
    bst * b = new bst();

    for(int i = 0; i < n; ++i){
        b->add(a[i]);
    }

    b->print();
    cout << endl;
    /*
    for(int i = 0; i <= 10; ++i){
        cout << i << " " << b->find(i) << endl;
    }
    cout << endl;
    */
    int x;
    cin >> x;
    b->del(x);
    b->print();

    return 0;
}