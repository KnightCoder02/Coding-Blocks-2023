#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(){
    int data;
    string hasLeft, hasRight;
    cin >> data >> hasLeft;

    Node *root = new Node(data);

    if(hasLeft == "true"){
        root->left = buildTree();
    }

    cin >> hasRight;

    if(hasRight == "true"){
        root->right = buildTree();
    }
    return root;
}

int sumOfNodes(Node *root){
    if(root == NULL){
        return 0;
    }

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main(){
    Node *root = buildTree();
    int result = sumOfNodes(root);
    cout << result;
}