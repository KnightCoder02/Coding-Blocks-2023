#include<iostream>
#include<queue>
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

node* insertInBST(node* root, int data){
    // It insert a node in BST
    if(!root){
        root = new node(data);
        return root;
    }

    if(data < root->data){
        root->left = insertInBST(root->left, data);
    }
    else{
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node* createBST(){
    // It takes input one by one and give to insertInBST function
    node* root = NULL;
    int data;
    cin >> data;

    while(data != -1){
        root = insertInBST(root, data);
        cin >> data;
    }
    return root;
}

void printRange(node* root, int k1, int k2){
    if(!root){
        return;
    }

    printRange(root->left, k1, k2);
    if(root->data >= k1 && root->data <= k2){
        cout << root->data << " ";
    }
    printRange(root->right, k1, k2);
}

int main(){
    // Input: 8 3 10 1 6 14 4 7 13 -1
    node* root = NULL;
    root = createBST();
    printRange(root, 7, 13);
}