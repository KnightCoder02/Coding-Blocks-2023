#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int* a = new int[n];
    int* b = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int q, x;
    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> x;
        x = x % n;
        
        for(int j = 0; j < n; j++){
            int pos = j - x;
            if(pos < 0){
                pos += n;    
            }

            b[j] = a[j] + a[pos];
        }
        for(int j = 0; j < n; j++){
            a[j] = b[j];
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + a[i];
    }
    cout << sum;
    delete[] a;
    delete[] b;
}