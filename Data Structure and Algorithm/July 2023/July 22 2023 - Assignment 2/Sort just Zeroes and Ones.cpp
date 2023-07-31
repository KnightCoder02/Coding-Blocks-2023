#include<iostream>
using namespace std;
int main(){
    int n, count = 0;
    cin >> n;

    int* a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        
        if(a[i] == 0){
            count++;
        }
    }

    for(int i = 0; i < count; i++){
        a[i] = 0;
    }

    for(int i = count; i < n; i++){
        a[i] = 1;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    delete[] a;
}