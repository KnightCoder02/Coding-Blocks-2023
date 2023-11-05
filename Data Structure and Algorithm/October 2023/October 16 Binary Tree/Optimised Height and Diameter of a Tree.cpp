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

class Pair{
    public:
    int height;
    int diameter;
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

Pair fastDiameter(node* root){
    // base case
    if(!root){
        Pair p;
        p.height = p.diameter = 0;
        return p;
    }

    // recursive case
    // left = {height, diameter}, right = {height, diameter}
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    Pair p;
    p.height = max(left.height, right.height) + 1;

    int op1 = left.height + right.height;
    int op2 = left.diameter;
    int op3 = right.diameter;
    p.diameter = max(op1, max(op2, op3));
    return p;
}

int main(){
    // input: 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    node* root = buildTree();   
    Pair ans = fastDiameter(root);
    cout << "Fast Height of Tree: " << ans.height;
    cout << "\nFast Diameter: " << ans.diameter;
}