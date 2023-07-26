#include<iostream>
#include<climits>
using namespace std;
int main() {
	int lar = INT_MIN;
	int n;
	for(int i = 1; i <= 3; i++){
		cin >> n;
		if(n > lar){
			lar = n;
		}
	}
	cout << lar;
	return 0;
}