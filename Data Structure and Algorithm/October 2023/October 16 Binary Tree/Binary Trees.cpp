#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left, *right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* buildTree(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    node* root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Pre-Order
void preorder(node *root){
    if(!root){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// In-Order
void inorder(node* root){
    if(!root){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Post-Order
void postorder(node* root){
    if(!root){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    // input: 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    node* root = buildTree();
    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;
}