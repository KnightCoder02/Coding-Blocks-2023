#include <iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKSortedArrays(vector<vector<int>>v){
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> heap;

    for(int i = 0; i < v.size(); i++){ //make a heap with K elements  
        heap.push({v[i][0], {i, 0}});
    }

    while(!heap.empty()){
        node currentNode = heap.top();
        heap.pop();
        int element = currentNode.first;
        int x = currentNode.second.first;
        int y = currentNode.second.second;

        if(y + 1 < v[x].size()){
            heap.push({v[x][y + 1],{x, y + 1}});
        }
        result.push_back(element);
    }
    return result;
}

int main(){
	int m, n;
	cin >> m >> n;
    
    vector<vector<int>> v(m,vector<int>(n));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> v[i][j];
		}
	}

    vector<int> output = mergeKSortedArrays(v);

    for(int x : output){
        cout << x << " ";
    }
}