#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;

    int digits = 0;
    int position = 1;

    while(n > 0){
        int last_digit = n % 10;      
        digits += position * pow(10, last_digit - 1);
        n /= 10;
        position++;
    }

    cout << digits << endl;
}