#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
TreeNode* insertNode(TreeNode* root, int val){
    if(!root){
        return new TreeNode(val);
    }

    if(val < root->val){
        root->left = insertNode(root->left, val);
    }
    else{
        root->right = insertNode(root->right, val);
    }

    return root;
}

// Function to find the Lowest Common Ancestor in a BST
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q){
    if(!root){
        return nullptr;
    }

    // If both p and q are smaller than the root, LCA must be in the left subtree
    if(p < root->val && q < root->val){
        return lowestCommonAncestor(root->left, p, q);
    }

    // If both p and q are greater than the root, LCA must be in the right subtree
    else if(p > root->val && q > root->val){
        return lowestCommonAncestor(root->right, p, q);
    }

    // If one is smaller and the other is greater, root is the LCA
    else{
        return root;
    }
}

// Function to build a BST
TreeNode* buildBST(int n){
    if(n <= 0){
        return nullptr;
    }

    int val;
    cin >> val;

    TreeNode* root = new TreeNode(val);

    for(int i = 1; i < n; ++i){
        cin >> val;
        insertNode(root, val);
    }

    return root;
}

int main(){
    int n;
    cin >> n;

    // Build the BST
    TreeNode* root = buildBST(n);

    int p, q;
    cin >> p >> q;

    // Find the Lowest Common Ancestor
    TreeNode* lca = lowestCommonAncestor(root, p, q);

    // Display the LCA value
    cout << lca->val << endl;
}