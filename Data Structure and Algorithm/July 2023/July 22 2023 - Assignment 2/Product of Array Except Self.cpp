#include<iostream>
using namespace std;
int main(){
    int n;
    int a[100000];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long int b[100000];
    for(int i = 0; i < n; i++) {
        b[i] = 1;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j){
                continue;
            }
            b[i] *= a[j];
        }
        
        cout << b[i] << " ";
    }
}