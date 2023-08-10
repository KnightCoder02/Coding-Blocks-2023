#include<iostream>
using namespace std;
int main(){
    string c = "abcd";
    int n = c.length();
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n - i; j++){
            cout << c.substr(i, j) << " ";
        }
        cout << endl;
    }
}