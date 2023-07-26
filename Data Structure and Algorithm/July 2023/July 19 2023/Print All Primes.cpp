#include<iostream>
using namespace std;
bool checkPrime(int n){
    int i;
    for(i = 2; i <= n; i++){
        if(n % i == 0){
            break;
        }
    }

    if(i == n){
        return true;
    }
    else{
        return false;
    }
}

void printAllPrime(int n){
    for(int i = 2; i <= n; i++){
        if(checkPrime(i)){
            cout << i << " ";
        }
    }
}

int main(){
    int n;
    cin >> n;
    printAllPrime(n);
}