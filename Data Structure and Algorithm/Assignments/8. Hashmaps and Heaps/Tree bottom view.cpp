#include<iostream>
#include<queue>
#include<map>
using namespace std;
class node{
	public:
	int data;
	node* left, *right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(){
		queue<node*> q;
		
		int d;
		cin >> d;
		
		node* root = new node(d);
		q.push(root);
		
		while(!q.empty()){
			node*temp = q.front();
			q.pop();
			
			int rc, lc;
			cin >> rc >> lc;
			
			if(rc != -1){
				temp->left = new node(rc);
				q.push(temp->left);
			}

			if(lc != -1){
				temp->right = new node(lc);
				q.push(temp->right);
			}
		}
		return root;
}

void helper(node*rt, map<int, pair<int, int>>&hashmap, int level, int hd){
	if(rt == NULL){
		return;
	}

	if(hashmap.find(hd) == hashmap.end()){
		hashmap.insert({hd,{rt->data,level}});
	}

	else{
		pair<int , int> p = hashmap[hd];
		if(level >= p.second){
			hashmap[hd] = {rt->data,level};
		}
	}

	helper(rt->left, hashmap, level + 1, hd - 1);
	helper(rt->right, hashmap, level + 1, hd + 1);
}

void TreeBottomView(node*rt){
	map<int, pair<int, int>> hashmap;
	helper(rt, hashmap, 0, 0);
	
	for(auto it : hashmap){
		cout << it.second.first << " ";
	}
	cout << endl;
}

int main(){
	node* root = NULL;
	root = buildTree();
	TreeBottomView(root);
}