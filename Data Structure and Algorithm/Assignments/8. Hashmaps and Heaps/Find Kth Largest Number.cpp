#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int k;
	cin >> n >> k;
	int a[1000000];

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);
	k = n - k;
	
	int count = 0;
	for(auto x : a){
		if(count == k){
			cout << x << endl;
		}
		count++;
	}
}