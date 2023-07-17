#include<iostream>
using namespace std;
int main(){
    int n, d, ans = 0;
    cin >> n; //Initialization of number

    for(; n > 0; n /= 10){
        d = n % 10;
        ans = ans * 10 + d;
    }
    cout << ans;

    // while(n > 0){
    //     d = n % 10;
    //     ans = ans * 10 + d;
    //     n /= 10;
    // }
    // cout << ans;
}