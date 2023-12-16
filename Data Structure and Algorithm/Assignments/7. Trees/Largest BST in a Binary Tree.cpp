#include<iostream>
#include<climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

struct SubtreeInfo{
    bool isBST;
    int size;
    int min_val;
    int max_val;

    SubtreeInfo(bool isBST, int size, int min_val, int max_val)
        : isBST(isBST), size(size), min_val(min_val), max_val(max_val) {}
};

// Function to construct a binary tree from preorder and inorder traversals
TreeNode* buildTree(int pre[], int in[], int& preIndex, int inStart, int inEnd){
    if(inStart > inEnd){
        return nullptr;
    }

    TreeNode* root = new TreeNode(pre[preIndex++]);

    int inIndex;
    for(inIndex = inStart; inIndex <= inEnd; ++inIndex){
        if(in[inIndex] == root->key){
            break;
        }
    }

    root->left = buildTree(pre, in, preIndex, inStart, inIndex - 1);
    root->right = buildTree(pre, in, preIndex, inIndex + 1, inEnd);
    return root;
}

SubtreeInfo largestBSTUtil(TreeNode* root){
    if(!root){
        return {true, 0, INT_MAX, INT_MIN};
    }

    SubtreeInfo leftInfo = largestBSTUtil(root->left);
    SubtreeInfo rightInfo = largestBSTUtil(root->right);

    if(leftInfo.isBST && rightInfo.isBST && root->key > leftInfo.max_val && root->key < rightInfo.min_val){
        int size = 1 + leftInfo.size + rightInfo.size;
        int min_val = (leftInfo.size == 0) ? root->key : leftInfo.min_val;
        int max_val = (rightInfo.size == 0) ? root->key : rightInfo.max_val;
        return {true, size, min_val, max_val};
    }

    return {false, max(leftInfo.size, rightInfo.size), 0, 0};
}

int largestBSTSize(TreeNode* root){
    return largestBSTUtil(root).size;
}

int main(){
    int n;
    cin >> n;

    int preorder[n], inorder[n];
    for(int i = 0; i < n; ++i){
        cin >> preorder[i];
    }

    for(int i = 0; i < n; ++i){
        cin >> inorder[i];
    }

    int preIndex = 0;
    TreeNode* root = buildTree(preorder, inorder, preIndex, 0, n - 1);

    int result = largestBSTSize(root);
    cout << result << endl;
}