#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;

    int digits = log10(n) + 1;
    int inverse = 0;

    for(int i = 1; i <= digits; i++){
        int digit = n % 10;
        inverse += i * pow(10, digit - 1);
        n /= 10;
    }

    cout << inverse << endl;
}