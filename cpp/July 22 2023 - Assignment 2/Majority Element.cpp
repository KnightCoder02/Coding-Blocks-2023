#include<iostream>
using namespace std;
int main() {
    int a[100000], n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n ; j++){
            if(a[i] == a[j]){
                count++;
            }
        }

        if(count > n/2){
            cout << a[i];
            break;
        }
    }
}