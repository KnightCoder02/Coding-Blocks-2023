#include<iostream>
using namespace std;
int main(){
    int a[10000], n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= a[i];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n - 2 - i; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << a[i] << ",";
    }
}