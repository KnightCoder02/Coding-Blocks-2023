#include<iostream>
using namespace std;
void printPrimeOrNot(int n){
    int i;
    for(i = 2; i <= n; i++){
        if(n % i == 0){
            break;
        }
    }

    if(i == n){
        cout << "Prime";
    }
    else{
        cout << "Not Prime";
    }
}

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

int main(){
    int n;
    cin >> n;
    // printPrimeOrNot(n);

    bool ans = checkPrime(n);
    if(ans == true){
        cout << "Prime";
    }
    else{
        cout << "Not Prime";
    }
}