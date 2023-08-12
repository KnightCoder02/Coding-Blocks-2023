#include<iostream>
using namespace std;
int main(){
    char c[100];
    int x;
    
    cin >> x;

    //  To get a white space string input after integer, always ignore white space character
    cin.get(); //It read white space character but does not store it anywhere.

    cin.getline(c,100);
    cout << x << endl;
    cout << c << endl;
}