#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int n;

    cout << "Enter n(max: 100): ";
    cin >> n;

    for (int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}