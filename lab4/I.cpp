#include <iostream>

using namespace std;

struct Node{
    int data, cnt;
    Node * left;
    Node*right;
    Node(int data){
        cnt = 1;
        this->data = data;
        left = right = NULL;
    }
};

Node * add(Node * root,int data){
    if(root == NULL){
        return new Node(data);
    }
    if(root->data == data) {
        root->cnt++;
        return root;
    }
    else if(root->data > data){
        if(root->left == NULL){
            root->left =  new Node(data);
        }else {
            root->left = add(root->left, data);
        }
    }
    else if(root->data < data){
        if(root->right == NULL){
            root->right = new Node(data);
        }
        else{
            root->right = add(root->right, data);
        }
    }
    return root;
}

Node *del(Node * root, int data){
    if(root == NULL){
        return NULL;
    }
    else if(root->data > data){
        root->left = del(root->left, data);
        return root;
    }
    else if(root->data < data){
        root->right = del(root->right, data);
        return root;
    }
    else if (root->data == data){
        if(root->cnt > 0){
            root->cnt--;
        }
    }
    return root;
}

Node * find(Node * root, int target){
    if(root == NULL){
        return NULL;
    } else if(root->data == target){
        return root;
    }
    else if(root->data < target){
        return find(root->right, target);
    }
    else{
        return find(root->left, target);
    }
}

int main(){
    int n;
    cin>>n;
    Node * root = NULL;

    while(n--){
        string s;int x;
        cin>>s>>x;
        if(s == "insert"){
            root = add(root,x);
        }
        else if(s == "cnt"){
            Node * node = find(root, x);
            if(node == NULL){
                cout<<0<<"\n";
            }
            else{
                cout<<node->cnt<<"\n";
            }
        }
        else{
            root = del(root, x);
        }
    }

    return 0;
}