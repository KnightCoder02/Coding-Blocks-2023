#include<iostream>
using namespace std;
int a = -100;
int main(){
    int a = 1, b = 20;

    if(b > 0){
        int a = 100, x = 200;
        // :: --> Scope resolution operator
        cout << "Global a: " << ::a << endl; //Global Variable
        cout << a << endl;
    }
    
    cout << a << endl;
    cout << b << endl;
    // cout << x << endl; ==> Error: x is not defined
}