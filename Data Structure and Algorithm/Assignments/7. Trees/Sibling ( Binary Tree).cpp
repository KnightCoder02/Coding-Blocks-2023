#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s){
    if(s == "true"){
        int d;
        cin >> d;
        
        node *root = new node(d);
        string l;
        cin >> l;
        
        if(l == "true"){
            root->left = build(l);
        }

        string r;
        cin >> r;
        
        if(r == "true"){
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

void printNodesWithoutSibling(node *root){
    if(root == NULL){
        return;
    }

    if(root->left && !root->right){
        cout << root->left->data << " ";
    }

    if(root->right && !root->left){
        cout << root->right->data << " ";
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

int main(){
    node *root = build("true");
    printNodesWithoutSibling(root);
}