// Macros are also constants only
// Macros are created using #define MACRO_NAME VALUE
// Macros are never evaluated. It paste below as same as define 
#include<iostream>
using namespace std;
#define Print cout <<
#define Start int main(){
#define Pi 3.14
#define Pii 3.14+1

Start
    cout << "Hello using cout" << endl;
    Print "Hello using macro" << endl;
    Print 2 * Pi * 1 << endl; //cout << 2 * 3.14 * 1
    Print 2 * Pii * 1 << endl; // cout << 2 * 3.14+1 * 1
}