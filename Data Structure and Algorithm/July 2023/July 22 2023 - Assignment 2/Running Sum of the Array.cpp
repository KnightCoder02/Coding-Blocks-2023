#include<iostream>
using namespace std;
int main(){
    int n, ar[1000];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    cout << ar[0] << " ";
    for(int i = 1; i < n; i++){
        ar[i] += ar[i - 1];
        cout << ar[i] << " ";
    }
}