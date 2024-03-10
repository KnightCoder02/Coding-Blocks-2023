#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level order traversal
TreeNode* buildTree(const vector<int>& levelOrder){
    if(levelOrder.empty()){
        return nullptr;
    }

    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < levelOrder.size()){
        TreeNode* current = q.front();
        q.pop();

        if(levelOrder[i] != -1){
            current->left = new TreeNode(levelOrder[i]);
            q.push(current->left);
        }
        i++;

        if(i < levelOrder.size() && levelOrder[i] != -1){
            current->right = new TreeNode(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Function to print nodes at each vertical level
void verticalTraversal(TreeNode* root, int column, map<int, vector<int>>& verticalLevels){
    if(!root){
        return;
    }

    verticalLevels[column].push_back(root->key);
    verticalTraversal(root->left, column - 1, verticalLevels);
    verticalTraversal(root->right, column + 1, verticalLevels);
}

int main(){
    int n;
    cin >> n;

    vector<int> levelOrder((1 << n) - 1);
    for(int i = 0; i < (1 << n) - 1; ++i){
        cin >> levelOrder[i];
    }

    TreeNode* root = buildTree(levelOrder);
    map<int, vector<int>> verticalLevels;
    verticalTraversal(root, 0, verticalLevels);

    // Print nodes at each vertical level
    for(auto& entry : verticalLevels){
        for(int value : entry.second){
            cout << value << " ";
        }
    }
}