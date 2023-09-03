#include<iostream>
using namespace std;
int main(){
	long long int r, c;
	cin >> r >> c;
	long long int arr[r][c];
	
	for(long long int i = 0; i < r; i++){
		for(long long int j = 0; j < c; j++){
			cin >> arr[i][j];
		}
	}
	
	long long int r1 = 0, c1 = 0;
	long long int count = 0;
	long long int x = r * c;
	while(r1 < r && c1 < c){
		if(count == x){
			break;
		}

		for(long long int i = r1; i < r; i++){
			cout << arr[i][c1] << ", ";
			count++;
		}
		
		c1++;
		if(count == x){
			break;
		}

		for(long long int i = c1; i < c; i++){
			cout << arr[r-1][i] << ", ";
			count++;
		}

		r--;
		if(count == x){
			break;
		}

		if(r1 < r && c1 < c){
			for(long long int i = r - 1; i >= r1; i--){
				cout << arr[i][c-1] << ", ";
				count++;
			}
			c--;
		}

		if(r1 < r && c1 < c){
			for(long long int i = c - 1; i >= c1; i--){
				cout << arr[r1][i] << ", ";
				count++;
			}
			r1++;
		}		
	}
	cout << "END";
}