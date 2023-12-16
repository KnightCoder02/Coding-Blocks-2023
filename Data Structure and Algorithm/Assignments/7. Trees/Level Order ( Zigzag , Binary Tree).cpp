#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void zigzagOrder(Node* root){
    if(!root){
        return;
    }

    queue<Node*> q;
    stack<Node*> s;

    bool leftToRight = true;
    q.push(root);

    while(!q.empty()){
        int levelSize = q.size();

        for(int i = 0; i < levelSize; ++i){
            Node* current = q.front();
            q.pop();

            if(leftToRight){
                cout << current->data << " ";
            }
            else{
                s.push(current);
            }

            if(current->left){
                q.push(current->left);
            }

            if(current->right){
                q.push(current->right);
            }
        }

        while(!s.empty()){
            Node* current = s.top();
            s.pop();
            cout << current->data << " ";
        }

        leftToRight = !leftToRight;
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(73);

    zigzagOrder(root);
}