// Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2
#include<iostream>
using namespace std;
int main(){
    int n = 1, i = 1, count = 0;
    int num1, num2;
    cin >> num1 >> num2;

    while(true){
        if((3 * i + 2) % num2 != 0){
            cout << (3 * i + 2) << endl;
            count++;
        }

        if(count == num1){
            break;
        }
        i++;
    }
}
