#include<iostream>
using namespace std;
int main(){
    int n, i;
    cin >> n;
    int a[100000];
    for(i = 0; i < n; i++){
        cin >> a[i];
    }

    int b[100000];
    for(i = 0; i < n; i++){
        b[a[i]] = i;
    }

    for(i = 0; i < n; i++){
        cout << b[i] << " ";
    }
}