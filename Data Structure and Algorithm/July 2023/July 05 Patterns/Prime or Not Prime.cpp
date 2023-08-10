#include<iostream>
using namespace std;
int main(){
    int n, i = 2;
    cin >> n;

    if(n == 1){
        cout << "Not allowed";
        return 0;
    }
    
    while(i <= n - 1){
        if(n % i == 0){
            cout << "Not Prime";
            return 0;
        }
        i = i + 1;
    }
    cout << "Prime";
}