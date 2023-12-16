#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to build a binary search tree from a sorted array
TreeNode* buildBST(const vector<int>& sortedArray, int start, int end){
    if(start > end){
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(sortedArray[mid]);

    root->left = buildBST(sortedArray, start, mid - 1);
    root->right = buildBST(sortedArray, mid + 1, end);
    return root;
}

// Function to perform reverse in-order traversal and update node values
void modifyBST(TreeNode* root, int& sum){
    if(!root){
        return;
    }

    modifyBST(root->right, sum);
    sum += root->key;

    root->key = sum;
    modifyBST(root->left, sum);
}

// Function to print pre-order traversal of the tree
void printPreOrder(TreeNode* root){
    if(root){
        cout << root->key << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> inorder(n);
    for(int i = 0; i < n; ++i){
        cin >> inorder[i];
    }

    // Build the binary search tree from the given inorder array
    TreeNode* root = buildBST(inorder, 0, n - 1);

    int sum = 0;
    // Perform reverse in-order traversal and update node values
    modifyBST(root, sum);

    // Print pre-order traversal of the new tree
    printPreOrder(root);
}