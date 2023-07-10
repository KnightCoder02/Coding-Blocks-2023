#include<iostream>
using namespace std;
int main(){
    char ch = 'A';
    cout << 'A' + 1 << endl;

    char c = 'A';
    c = c + 1;
    cout << c << endl;

    int acode;

    while (ch <= 'Z'){
        acode = ch;
        cout << ch << " : " << acode << endl;
        ch = ch + 1;
    }
}