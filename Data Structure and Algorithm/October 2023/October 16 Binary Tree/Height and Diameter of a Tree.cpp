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

int height(node* root){
    if(!root){
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

int diameter(node* root){
    if(!root){
        return 0;
    }

    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}

int main(){
    // input: 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    node* root = buildTree();
    cout << "\nHeight of Tree: " << height(root);
    cout << "\nDiameter: " << diameter(root);
}