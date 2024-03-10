#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class node{
    public:
    int data ;
    node*left;
    node*right;
 
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
 
node* temp = NULL;
node* buildtree(){
	string s;
	cin >> s;
	if(s == "false"){
		return NULL;
	}

	if(s == "true"){
		buildtree();
	}

	if(s != "true" && s != "false"){
		node* root = new node(stoi(s));
		root->left = buildtree();
		root->right = buildtree();
		temp = root;
	}
	return temp;
}
 
vector<vector<int>>ans; // to store all path 
vector<int>res; // to store temp path
 
void rootToLeaf(node* root, int sum, int cs){
	if(root == NULL){
		return;
	} 
 
	res.push_back(root->data); // push to res
	cs += root->data; // add to sum
 
	if(root->left == NULL and root->right == NULL and cs == sum){
		ans.push_back(res);  // if cs == sum and its root node add to ans
		res.pop_back();  // remove this node and return
		return;
	}
 
	rootToLeaf(root->left, sum, cs); // call on left
 	rootToLeaf(root->right, sum, cs); // call on right
	res.pop_back();  // finally the backtracking step
}
 
int main(){
	node* root = buildtree();
	int k;
	cin >> k;
	int curSum = 0;
 
	rootToLeaf(root, k, curSum);
	for(auto v : ans){
		for(auto x : v){
			cout << x << " ";
		}
		cout << endl;
	}
}