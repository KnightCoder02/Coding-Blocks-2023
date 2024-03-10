#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *left, *right;
	
	Node(int d){
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

void buildTree(Node* &root){
	string left, right;
	int d;
	cin >> d;
	
	root = new Node(d);
	cin >> left;
	
	if(left == "true"){
		buildTree(root->left);
	}

	cin >> right;
	if(right == "true"){
		buildTree(root->right);
	}
}

Node* removeLeaves(Node* root){
	if(root == nullptr){
		return root;
	}

	if(!root->left && !root->right){
		delete root;
		return nullptr;
	}

	root->left = removeLeaves(root->left);
	root->right = removeLeaves(root->right);
	return root;
}

void PrintTree(Node* root){
	if(root == nullptr){
		return;
	}

	if(root->left){
		cout << root->left->data << " => ";
	}
	else{
		cout << "END => ";
	}

	cout << root->data;

	if(root->right){
		cout << " <= " << root->right->data;
	}
	else{
		cout << " <= END";
	}
	
	cout << endl;
	PrintTree(root->left);
	PrintTree(root->right);
}

int main(){
	Node* root = nullptr;
	buildTree(root);
	removeLeaves(root);
	PrintTree(root);
}