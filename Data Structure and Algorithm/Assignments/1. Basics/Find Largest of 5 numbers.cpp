#include<iostream>
#include<climits>
using namespace std;
int main(){
	int lar = INT_MIN;
	int no;
	
	for(int i = 0; i < 5; i++){
		cin >> no;
		if(no > lar){
			lar = no;
		}
	}
	cout << lar;
}
