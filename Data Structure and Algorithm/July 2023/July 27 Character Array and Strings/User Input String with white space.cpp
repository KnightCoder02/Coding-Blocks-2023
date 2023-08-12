#include<iostream>
using namespace std;
int main(){
    
    // cin.getline(array_name, number_of_characters_toinput, delimiter); It takes string with white space as input from user
    // Default delimiter is '\n' 
    
    char c[1000];
    cin.getline(c, 1000, '$');
    cin.getline(c, 1000);
    cout << c << endl;
}