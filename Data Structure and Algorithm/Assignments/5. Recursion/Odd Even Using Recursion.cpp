#include<iostream>
using namespace std;

void printOddEven(int n){
    if(n <= 0){
        return;
    }

    if(n % 2 == 1){
        cout << n << endl;
    }

    printOddEven(n - 1);

    if(n % 2 == 0){
        cout << n << endl;
    }
}

int main(){
    int N;
    cin >> N;
    printOddEven(N);
}