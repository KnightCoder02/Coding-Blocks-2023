#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;

	int a[1000][1000];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];	
		}
	}

	int flag = 1;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(a[i][j] != 0 and j > i){
				flag = 0;
			}
		}
	}

	if(flag){
		cout << "true";
	}
		
	if(flag == 0){
		cout << "false";
	}	
}