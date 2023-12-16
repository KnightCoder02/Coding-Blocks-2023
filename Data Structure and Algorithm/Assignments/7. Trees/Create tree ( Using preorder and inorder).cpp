#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& indexMap){
    if(preIndex >= preorder.size() || inStart > inEnd){
        return nullptr;
    }

    int rootData = preorder[preIndex++];
    Node* root = new Node(rootData);

    int inIndex = indexMap[rootData];

    root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1, indexMap);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd, indexMap);
    return root;
}

void modifiedPreorder(Node* root) {
    if(root){
        cout << (root->left ? to_string(root->left->data) : "END");
        cout << " => " << root->data << " <= ";
        cout << (root->right ? to_string(root->right->data) : "END");
        cout << endl;

        modifiedPreorder(root->left);
        modifiedPreorder(root->right);
    }
}

int main(){
    int n, m;
    cin >> n;

    vector<int> preorder(n);
    for(int i = 0; i < n; ++i){
        cin >> preorder[i];
    }

    cin >> m;
    vector<int> inorder(m);
    
    for(int i = 0; i < m; ++i){
        cin >> inorder[i];
    }

    unordered_map<int, int> indexMap;
    
    for(int i = 0; i < m; ++i){
        indexMap[inorder[i]] = i;
    }

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, preIndex, 0, m - 1, indexMap);

    modifiedPreorder(root);
}