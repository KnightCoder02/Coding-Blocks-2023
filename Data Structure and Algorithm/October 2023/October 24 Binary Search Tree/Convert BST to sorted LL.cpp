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

class LinkedList{
    public:
    node* head, *tail = NULL;
};

LinkedList BSTtoLL(node* root){
    LinkedList l;
    // base case
    if(!root){
        l.head = l.tail = NULL;
        return l;
    }

    // recursive case
    if(root->left && root->right){
        LinkedList left = BSTtoLL(root->left);
        LinkedList right = BSTtoLL(root->right);
        left.tail->right = root;
        root->right = right.head;
        l.head = left.head;
        l.tail = right.tail;
        return l;
    }
    else if(root->left && !root->right){
        LinkedList left = BSTtoLL(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
        return l;
    }
    else if(!root->left && root->right){
        LinkedList right = BSTtoLL(root->right);
        root->right = right.head;
        l.head = root;
        l.tail = right.tail;
        return l;
    }
    else{ //!root->left && !root->right
        l.head = l.tail = root;
        return l;
    }
}

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

int main(){
    // Input: 3 1 5 2 4 6 -1
    node* root = NULL;
    root = createBST();
    
    LinkedList l = BSTtoLL(root);
    node* head = l.head;
    while(head){
        cout << head->data << "-->";
        head = head->right;
    }
    cout << "NULL";
}