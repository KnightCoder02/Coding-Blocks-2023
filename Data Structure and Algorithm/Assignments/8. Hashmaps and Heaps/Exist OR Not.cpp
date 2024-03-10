#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		unordered_set<int>m;
		for(int i = 0 ;i < n; i++){
			m.insert(a[i]);
		}

		int q;
		cin >> q;
		
		while(q--){
			int g;
			cin >> g;
			
			if(m.find(g) != m.end()){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
	}
}