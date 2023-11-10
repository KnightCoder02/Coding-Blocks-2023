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

node* arrayBalancedBST(int *a, int s, int e){
    // base case
    if(s > e){
        return NULL;
    }

    // recursive case
    int m = (s + e) / 2;
    node* root = new node(a[m]);
    root->left = arrayBalancedBST(a, s, m - 1);
    root->right = arrayBalancedBST(a, m + 1, e);
    return root;
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(int);
    node* root = NULL;
    root = arrayBalancedBST(a, 0, n - 1);
    printLevelOrder(root);
}