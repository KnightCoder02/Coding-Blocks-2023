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

class Pair{
    public:
    int height;
    bool isBalanced;
    
    Pair(){
        height = 0;
        isBalanced = true;
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

Pair isBalancedTree(node* root){
    Pair p;
    // base case
    if(!root){
        return p;
    }

    // recursive case
    Pair left = isBalancedTree(root->left);
    Pair right = isBalancedTree(root->right);
    p.height = max(left.height, right.height) + 1;

    if(abs(left.height - right.height) <= 1 && left.isBalanced && right.isBalanced){
        p.isBalanced = true;
    }
    else{
        p.isBalanced = false;
    }
    return p;
}

int main(){
    // Input: 8 3 10 1 6 14 4 7 13 -1
    node* root = NULL;
    root = createBST();
    
    Pair ans = isBalancedTree(root);
    if(ans.isBalanced){
        cout << "Balanced\n";
    }
    else{
        cout << "Not Balanced\n";
    }

    cout << "Height: " << ans.height;
}