#include<iostream>
using namespace std;
int main(){
    long long i = 1, n, a, b, num1 = 0, num2 = 0, sum1 = 0, sum2 = 0;
    cin >> n;

    while(i <= n){
        cin >> a >> b;

        while(a != 0){
            num1 = num1 * 10 + a % 10;
            a = a / 10;
        }

        while(b != 0){
            num2 = num2 * 10 + b % 10;
            b = b / 10;
        }

        sum1 = num1 + num2;
        while(sum1 != 0){
            sum2 = sum2 * 10 + sum1 % 10;
            sum1 = sum1 / 10;
        }
        
        cout << sum2 << endl;
        sum1 = sum2 = num1 = num2 = 0;
        i++;
    }
}