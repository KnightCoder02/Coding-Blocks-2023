#include<iostream>
using namespace std;
int main(){
    char ch;
    cin >> ch;

    switch(ch){
        case 'N': case 'n':
            cout << "North";        break;
        case 'E': case 'e':
            cout << "East";         break;
        case 'S': case 's':
            cout << "South";        break;
        case 'W': case 'w':
            cout << "West";         break;
        default:
            cout << "Wrong Input";  break;
    }
}