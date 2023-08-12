#include<iostream>
using namespace std;
int factorial(int n){
    // base case
    if(n == 0){
        return 1;
    }

    // recursive case
    return n * factorial(n - 1);
}

int factorial(int n){
    // base case
    if(n == 0){
        return 1;
    }

    // recursive case, factorial(n) = n * factorial(n - 1);
    int small = factorial(n - 1);
    int big = n * small;
    return big;
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n);
}