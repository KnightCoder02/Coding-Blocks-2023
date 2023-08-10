#include<iostream>
using namespace std;
void reversedArray(int n){
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = n - 1; i >= 0; i--){
        cout << a[i] << endl;
    }

    delete[] a;
}

int main(){
    long long int n;
    cin >> n;

    reversedArray(n);
}