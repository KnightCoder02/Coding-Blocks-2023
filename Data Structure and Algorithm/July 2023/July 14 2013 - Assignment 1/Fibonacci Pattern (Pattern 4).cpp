/*
0
1 1
2 3 5
8 13 21 34
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    if(n >= 1){
        cout << 0 << endl;
    }

    if(n >= 2){
        cout << 1 << "\t" << 1 << endl;
    }

    int a = 1, b = 1, c = 2;
    for(int row = 3; row <= n; row++){
        for(int i = 0; i < row; i++){
            cout << c << "\t";
            a = b;
            b = c;
            c = a + b;
        }
        cout << endl;
    }
}