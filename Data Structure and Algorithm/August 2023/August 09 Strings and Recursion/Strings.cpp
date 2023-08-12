#include<iostream>
#include<cstring>
using namespace std;
int main(){
    // To create a string
    
    // char s[6] = "Hello";
    string s = "Hello";
    s = "Learning Strings!";

    for(int i = 0; i < s.size(); i++){
        cout << s[i] << "-";
    }
    cout << endl;

    // Concatenate
    s = "Hello";
    string x = s + " " + "world";
    cout << x << endl;
    cout << s << endl;

    // Insertion using push_back
    // Insert characters one by one: push_back
    string y;
    y.push_back('H');
    y.push_back('e');
    y.push_back('r');
    y.push_back('a');
    cout << y << "-" << y.size() << endl;

    // Whitespace character input
    string z;
    getline(cin, z); //To take white characters input

    // getline(cin, z, '@'); //To take white characters input using delimiter. Default delimiter is '\n'
    
    cout << z << endl; 
}