#include<iostream>
using namespace std;
int main(){
    string x = "abcdef";
    cout << x.substr(2, 3) << endl;
    cout << x.substr(2) << endl;

    for(int i = 0; i < x.size(); i++){
        cout << x[i] << ", Remaining string: " << x.substr(0, i) + x.substr(i + 1) << endl;
    }
}