#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, pair<int, int>> node;

void sort_(vector<vector<int>> v){
	priority_queue<node, vector<node>, greater<node>> pq;

	for(int i = 0; i < v.size(); i++){
		pq.push({v[i][0], {i, 0}});
	}

	while(!pq.empty()){
		node current = pq.top();
		pq.pop();

		cout << current.first << " ";
		int row = current.second.first;
		int col = current.second.second;

		if(col + 1 < v[row].size()){
			pq.push({v[row][col + 1], {row, col + 1}});
		}
	}
}

int main(){
	int r, c, x;
	cin >> r >> c;

	vector<vector<int>> v;

	for(int i = 0; i < r; i++){
		vector<int> v1;
		
		for(int j = 0; j < c; j++){
			cin >> x;
			v1.push_back(x);
		}
		v.push_back(v1);
	}

	sort_(v);
}