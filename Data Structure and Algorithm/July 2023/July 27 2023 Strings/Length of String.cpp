#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char c[1000];
    cin.getline(c, 1000, '$');
    
    int i = 0;
    for(i = 0; c[i] != '\0'; i++){

    }
    cout << "Length: " << i << endl;
    // cout << strlen(c) << endl; //Inbuild function to calculate length of string
}