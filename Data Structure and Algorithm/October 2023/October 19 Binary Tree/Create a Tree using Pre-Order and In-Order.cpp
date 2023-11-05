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

int pre[] = {8, 10, 1, 6, 3, 14};
int k = 0;
node* treeCreate(int *in, int s, int e){
    // base case
    if(s > e){
        return NULL;
    }

    // recursive case
    node* root = new node(pre[k]);
    k++;
    int index = -1;

    for(int i = s; i <= e; i++){
        if(in[i] == root->data){
            index = i;
            break;
        }
    }

    root->left = treeCreate(in, s, index - 1);
    root->right = treeCreate(in, index + 1, e);
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
    int in[] = {1, 10, 6, 8, 3, 14};
    node* root = treeCreate(in, 0, 5);
    printLevelOrder(root);
}