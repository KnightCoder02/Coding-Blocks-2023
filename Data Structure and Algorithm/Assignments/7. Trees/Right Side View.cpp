#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to print the right side view of a binary tree
void printRightSideView(TreeNode* root){
    if(!root){
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int levelSize = q.size();

        for(int i = 0; i < levelSize; ++i){
            TreeNode* current = q.front();
            q.pop();

            // Print the rightmost node at each level
            if(i == levelSize - 1){
                cout << current->key << " ";
            }

            if(current->left){
                q.push(current->left);
            }

            if(current->right){
                q.push(current->right);
            }
        }
    }
}

int main(){
    // Build the binary tree from level order traversal
    TreeNode* root = nullptr;
    
    int value;
    while(cin >> value){
        if(value == -1){
            continue; // skip null nodes
        }

        if(!root){
            root = new TreeNode(value);
        }
        else{
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()){
                TreeNode* current = q.front();
                q.pop();

                if(current->left == nullptr){
                    current->left = new TreeNode(value);
                    break;
                }
                else{
                    q.push(current->left);
                }

                if(current->right == nullptr){
                    current->right = new TreeNode(value);
                    break;
                }
                else{
                    q.push(current->right);
                }
            }
        }
    }

    // Print the right side view
    printRightSideView(root);
}