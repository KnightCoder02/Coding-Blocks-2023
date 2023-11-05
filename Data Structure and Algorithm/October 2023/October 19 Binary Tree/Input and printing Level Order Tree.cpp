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

node* buildLevelOrder(){
    int data, left, right;
    cout << "Enter the data for root node : ";
    cin >> data;
    if(data == -1){
        return NULL;
    }

    node* root = new node(data);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        q.pop();
        cout << "Enter children of " << f->data << " : ";
        cin >> left >> right;

        if(left != -1){
            f->left = new node(left);
            q.push(f->left);
        }

        if(right != -1){
            f->right = new node(right);
            q.push(f->right);
        }
    }

    return root;
}

void printLevelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        q.pop();

        if(f != NULL){
            cout << f->data << " ";
            
            if(f->left){
                q.push(f->left);
            }

            if(f->right){
                q.push(f->right);
            }
        }
        else{
            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

int main(){
    node* root = buildLevelOrder();
    printLevelOrder(root);
}