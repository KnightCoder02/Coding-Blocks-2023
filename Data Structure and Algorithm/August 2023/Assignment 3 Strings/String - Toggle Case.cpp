#include<iostream>
using namespace std;
void toggle(char c[]){
    for(int i=0; c[i]!='\0'; i++){
        if(c[i] >= 'A' && c[i] <= 'Z'){
            c[i] = tolower(c[i]);
        }
        else{
            c[i] = toupper(c[i]);
        }
    }
    cout << c;
}

int main(){
    char c[1000];
    cin >> c;
    toggle(c);
}