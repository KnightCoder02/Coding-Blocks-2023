// Write a function that returns the number of times digit is found in the number. Print the value returned.
#include<iostream>
using namespace std;
int main(){
    int n, digit, count = 0;
    cin >> n >> digit;

    while(n > 0){
        if(n % 10 == digit){
            count++;
        }
        n = n / 10;
    }
    cout << count;
}