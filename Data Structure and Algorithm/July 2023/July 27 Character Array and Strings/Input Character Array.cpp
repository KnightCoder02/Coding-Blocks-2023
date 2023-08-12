#include<iostream>
using namespace std;
void inputString(char *c, char delimiter = '\n'){
    char ch;
    int i = 0;
    ch = cin.get(); //It use to take single white space character input 
    while(ch != delimiter){
        c[i] = ch;
        i++;
        ch = cin.get();
    }
    c[i] = '\0';
}

int main(){
    char c[100];
    inputString(c);
    inputString(c, '$');

    //cin >> c; //It ignores white space characters
    cout << c; 
}