#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
	if(a.second != b.second){
		return a.second > b.second; 
	}
	else{
		return a.first<b.first;	
	}
}

int main(){
	int marks, n, i;
	cin >> marks >> n;

	vector<pair<string, int>> v;

	for(i = 0; i < n; i++){
		string s;
		int x;
		cin >> s >> x;
		
		if(x >= marks){
			v.push_back(make_pair(s, x));
		} 
	}

	sort(v.begin(), v.end(), comp);

	for(pair<string, int> p : v){ 
		cout << p.first << " " << p.second << endl;
	}
}