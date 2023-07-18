/*
ABCDEEDCBA
ABCDDCBA
ABCCBA
ABBA
AA
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    for(int row = 1; row <= n; row++){
        // Increasing Characters
        char ch = 'A';
        for(int i = 1; i <= n-row+1; i++){
            cout << ch << " ";
            ch++;
        }

        // Decreasing Characters
        ch--;
        for(int i = 1; i <= n-row+1; i++){
            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
}