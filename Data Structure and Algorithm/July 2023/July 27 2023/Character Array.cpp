#include<iostream>
using namespace std;
int main(){
    char a[] = "Welcome";
    cout << a << endl;

    for(int i = 0; a[i] != '\0'; i++){
        cout << a[i] << "-";
    }
    cout << endl;

    char b[] = {'H', 'e', 'l', 'l', 'o'};
    char c[] = {'w', 'o', 'r', 'l', 'd'};
    
    cout << b << endl; // It stores before array 'a' in memory and does not have null that's why it prints "HelloWelcome".
    
    cout << c << endl; // It stores before array 'b' and then array 'a' in memory and does not have null that's why it prints "WorldHelloWelcome".
}