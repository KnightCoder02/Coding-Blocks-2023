// Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2
#include<iostream>
using namespace std;
int main(){
    int i = 1, count = 0;
    int num1, num2;
    cin >> num1 >> num2;

    while(true){
        int x = 3 * i + 2;
        if(x % num2 != 0){
            cout << x << endl;
            count++;
        }

        if(count == num1){
            break;
        }
        i++;
    }
}