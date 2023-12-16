#include<iostream>
#include<queue>
#include<cmath>
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

pair<int, bool> isHeightBalancedOptimised(node *root){
    // Base case: an empty tree is balanced and has height 0
    if(root == NULL){
        return make_pair(0, true);
    }

    // Recursive case
    pair<int, bool> leftSubtree = isHeightBalancedOptimised(root->left);
    pair<int, bool> rightSubtree = isHeightBalancedOptimised(root->right);

    // Calculate the height of the current node
    int height = 1 + max(leftSubtree.first, rightSubtree.first);

    // Check if the subtrees are balanced and the current node is balanced
    bool balanced = abs(leftSubtree.first - rightSubtree.first) <= 1 && leftSubtree.second && rightSubtree.second;
    return make_pair(height, balanced);
}

int main(){
    node *root = build("true");
    cout << boolalpha << isHeightBalancedOptimised(root).second;
}