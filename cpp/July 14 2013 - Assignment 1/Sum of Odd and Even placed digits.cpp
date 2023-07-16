#include<iostream>
using namespace std;
int main(){
    int n, count = 1, even = 0, odd = 0;
    cin >> n;

    while(n != 0){
        int last_digit = n % 10;
        if(count % 2 == 0){
            even = even + last_digit;
        }
        else{
            odd = odd + last_digit;
        }
        count++;
        n /= 10;
    }

    cout << odd << endl << even << endl;
}