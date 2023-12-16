#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to insert a key into BST
TreeNode* insert(TreeNode* root, int key){
    if(!root){
        return new TreeNode(key);
    }

    if(key < root->key){
        root->left = insert(root->left, key);
    }
    else if(key > root->key){
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to print all nodes at distance k from the given node
void printKDistanceDown(TreeNode* root, int k){
    if(!root || k < 0){
        return;
    }

    if(k == 0){
        cout << root->key << " ";
        return;
    }

    printKDistanceDown(root->left, k - 1);
    printKDistanceDown(root->right, k - 1);
}

// Function to find the target node and print all nodes at distance k from it
int printKDistanceNodes(TreeNode* root, int target, int k){
    if(!root){
        return -1;
    }

    // If the target is found, print nodes at distance k downwards
    if(root->key == target){
        printKDistanceDown(root, k);
        return 0;
    }

    // Try to find the target in the left subtree
    int leftDist = printKDistanceNodes(root->left, target, k);
    if(leftDist != -1){
        // If the target is found in the left subtree, print nodes at distance k in the right subtree
        if(leftDist + 1 == k){
            cout << root->key << " ";
        }
        else{
            printKDistanceDown(root->right, k - leftDist - 2);
        }
        return leftDist + 1;
    }

    // Try to find the target in the right subtree
    int rightDist = printKDistanceNodes(root->right, target, k);
    if(rightDist != -1){
        // If the target is found in the right subtree, print nodes at distance k in the left subtree
        if(rightDist + 1 == k){
            cout << root->key << " ";
        }
        else{
            printKDistanceDown(root->left, k - rightDist - 2);
        }
        return rightDist + 1;
    }

    return -1;
}

int main(){
    int n, target, k;
    cin >> n;

    TreeNode* root = nullptr;

    // Insert nodes into the BST
    for(int i = 0; i < n; ++i){
        int key;
        cin >> key;
        root = insert(root, key);
    }

    // Input target node and distance k
    cin >> target >> k;

    // Print nodes at distance k from the target node
    printKDistanceNodes(root, target, k);
}