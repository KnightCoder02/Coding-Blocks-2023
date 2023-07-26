#include<iostream>
using namespace std;
int main(){
    int n, i = 0, r, a[10000];
    cin >> n;

    while(n != 0){
        r = n % 10;
        if(r == 0){
            r = 5;
        }
        a[i] = r;
        i++;
        n = n / 10;
    }
    
    for (int j = i - 1; j >= 0; j--) {
        cout << a[j];
    }
}