#include<iostream>
using namespace std;
int sum(int n){
    // base case
    if(n == 0){
        return 0;
    }

    // recursive case
    return n + sum(n - 1);
}

int sum(int n){
    // base case
    if(n == 0){
        return 0;
    }

    // recursive case, sum(n) = n + sum(n - 1);
    int small = sum(n - 1);
    int big = n + small;
    return big;
}

int main(){
    int n;
    cin >> n;
    cout << sum(n);
}