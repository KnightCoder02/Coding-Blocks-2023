#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int* a = new int[n];

    for(int i = 0; i < n; i++){
        a[i] = i + 1;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    delete[] a;

    // After deleting array a, using it will give segmentation fault
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}