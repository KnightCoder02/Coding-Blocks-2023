#include<iostream>
#include<cmath>
using namespace std;
#define ll long long int
int main(){
    ll n;
    cin >> n;

    ll n_copy = n, digits = 0;
    while(n != 0){
        digits++;
        n /= 10;
    }

    n = n_copy;
    ll sum = 0;
    while(n != 0){
        ll last_digit = n % 10;
        sum = sum + pow(last_digit, digits);
        n /= 10;
    }

    if(sum == n_copy){
        cout << "true";
    }
    else{
        cout << "false";
    }
}