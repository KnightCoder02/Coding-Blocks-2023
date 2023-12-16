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
    if (s == "true"){
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

void printLevelOrder(node *root){
    if(root == NULL){
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        while(size--){
            node *front = q.front();
            q.pop();

            cout << front->data << " ";

            if(front->left){
                q.push(front->left);
            }

            if(front->right){
                q.push(front->right);
            }
        }
        cout << endl;
    }
}

int main(){
    node *root = build("true");
    printLevelOrder(root);
}