#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<string>& inputList){
    if(inputList.empty()){
        return nullptr;
    }

    if(inputList[0] == "true"){
        inputList.erase(inputList.begin());
        
        int rootData = std::stoi(inputList[0]);
        inputList.erase(inputList.begin());
        
        Node* root = new Node(rootData);
        root->left = buildTree(inputList);
        root->right = buildTree(inputList);
        
        return root;
    }
    else{
        inputList.erase(inputList.begin());
        return nullptr;
    }
}

bool areStructurallyIdentical(Node* root1, Node* root2){
    if(!root1 && !root2){
        return true;
    }

    if(!root1 || !root2){
        return false;
    }

    return(areStructurallyIdentical(root1->left, root2->left) && areStructurallyIdentical(root1->right, root2->right));
}

int main(){
    string input1, input2;
    getline(cin, input1);
    getline(cin, input2);

    istringstream stream1(input1);
    istringstream stream2(input2);

    vector<string> inputList1, inputList2;
    string token;

    while(stream1 >> token){
        inputList1.push_back(token);
    }

    while(stream2 >> token){
        inputList2.push_back(token);
    }

    Node* root1 = buildTree(inputList1);
    Node* root2 = buildTree(inputList2);

    bool result = areStructurallyIdentical(root1, root2);
    cout << (result ? "true" : "false") << endl;
}