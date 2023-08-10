#include<iostream>
using namespace std;
int main(){
	int n;
    cin >> n;

    int* a = new int[n];
	int j = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

	for (int i = 0; i < n; i++){
		if (a[i] != 0) {
			swap(a[j], a[i]);
			j++;
		}
	}

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
    delete[] a;
}