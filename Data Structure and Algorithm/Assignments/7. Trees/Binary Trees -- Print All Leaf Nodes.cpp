#include<iostream>
#include<queue>
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
    cin >> data;

    if(data == -1){
        return NULL;
    }

    Node *root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *current = q.front();
        q.pop();

        int leftData, rightData;
        cin >> leftData >> rightData;

        if(leftData != -1){
            current->left = new Node(leftData);
            q.push(current->left);
        }

        if(rightData != -1){
            current->right = new Node(rightData);
            q.push(current->right);
        }
    }

    return root;
}

void printLeafNodes(Node *root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main(){
    Node *root = buildTree();
    printLeafNodes(root);
}